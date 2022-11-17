pushd .\
echo ON
"python.exe" "%1\CI_scripts\version.py"  "-g" "--path" "%1"

@REM cd "%1\LCP_PistonDriver"
@REM "ceedling" "test:all"
@REM cd ".."
popd
