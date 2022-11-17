#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import subprocess
import argparse
import datetime
import os

from error_code import ErrorCode

def dir_path(path):
    if os.path.isdir(path):
        return path
    else:
        raise argparse.ArgumentTypeError(f"readable_dir:{path} is not a valid path")

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Version helper')
	parser.add_argument('-g', '--generate', action='store_const', const=True, help='Generate a C header')
	parser.add_argument('--path', type=dir_path)
	args = parser.parse_args()
	cwd = os.getcwd()

	try:
		if args.path:
			os.chdir(args.path)
	except OSError:
		pass

from error_code import ErrorCode

VERSION_FILE_HEADER = """#ifndef VERSION_H
#define VERSION_H
		
#define SW_VERSION 	(\"{0}\")
#define SW_VER_MAJ	({1})
#define SW_VER_MIN	({2})
#define SW_BUILD	({3})
#define SW_HASH		(\"{4}\")
#define SW_DT		(\"{5}\")
			
#endif /* VERSION_H */
"""

def getCurrentBranch() -> str:
	print("Getting current branch")
	process = subprocess.run(["git", "rev-parse", "--abbrev-ref", "HEAD"], check=True, text=True, capture_output=True)
	if (process.returncode):
		return ""
	if (len(process.stdout) < 0):
		return ""
	return process.stdout.replace('\r','').replace('\n','')

def getLatestTag() -> str:
	branch = getCurrentBranch()
	if (branch == ""):
		return ""
	print("Getting latest tags for branch: {0}".format(branch))
	# process = subprocess.run(["git", "tag", "-l"], check=True, text=True, capture_output=True)
	process = subprocess.run(["git", "describe", "--tags", "--long"], check=True, text=True, capture_output=True)
	# process = subprocess.run("git", "describe", "--tags", "--long", check=True, capture_output=True)
	if (process.returncode):
		return ""
	if (len(process.stdout) < 0):
		return ""
	tags = process.stdout.split('\n')
	tags = list(filter(lambda x: x != '', tags))[0]
	# tags = list(filter(lambda x: x.rsplit('-')[-1] == branch, tags))
	print("Tags: {0}".format(tags))
	return tags

def generateHeaderFile() -> ErrorCode:
	ret = ErrorCode.OK
	latestTag = getLatestTag()
	if (latestTag == ""):
		errorCode = ErrorCode.WTF
		return errorCode
	print("Latest tag: {0}".format(latestTag))
	major = latestTag.split('.')[0].strip('v')
	minor = latestTag.split('.')[1].split('-')[0]
	version = latestTag.split('-')[0]
	build = latestTag.split('-')[1]
	hash = latestTag.split('-')[2]

	with open('.\\LCP_PistonDriver\\version.h', 'w+') as versionFile:
		fileContents = VERSION_FILE_HEADER.format(
			latestTag,
			major,
			minor, 
			build, 
			hash,
			datetime.datetime.now().strftime('%Y-%m-%d %H:%M')
			)
		versionFile.write(fileContents)
	return ret

def main() -> ErrorCode:
	errorCode = ErrorCode.OK
	if (args.generate):
		print("Generating header")
		errorCode = generateHeaderFile()
		if (errorCode.value):
			return errorCode
	return errorCode

if __name__ == '__main__':
	errorCode = main()
	sys.exit(errorCode.value)
	os.chdir(cwd)