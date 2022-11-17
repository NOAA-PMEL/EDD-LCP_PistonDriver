import datetime
import subprocess
import sys

def run(cmd):
    proc = subprocess.Popen( cmd,
        stdout = subprocess.PIPE,
        stderr = subprocess.PIPE
    )
    stdout, stderr = proc.communicate()

    return proc.returncode, stdout, stderr



if __name__ == "__main__":

    # Create Firmware Version
    ret_code, ver, stderr = run('git describe --tags --long')


    if ret_code == 0:
        # path = []
        path = './'
        # if(sys.argv[1]):
        #     path = f'{sys.argv[1]}/'
        path += 'src/version.h'
        print(f'{path=}')
        with open(path, 'w+') as f:
            f.write(
                "#ifndef _VERSION_H\n"
                "#define _VERSION_H\n"
                "\n"
                f"#define VERSION   ( {ver.decode().rstrip()} )\n"
                f"#define VERSION_DT    ( {datetime.datetime.now()} )\n"
                "\n"
                "#endif // _VERSION_H"
            )
        print(f'File src/firmware.h written.  Firmware version: {ver.decode()}')
    else:
        cmd_str = "git tag -a v0.1 -m 'First version'"
        raise ValueError(
            'No tags in Git Repository.  '
            f'Run the command: {cmd_str}'
            )


