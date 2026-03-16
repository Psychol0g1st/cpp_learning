\
$ErrorActionPreference = "Stop"

$outBin = "ellenorzes.exe"
$outTxt = "aktualis-stdout.txt"

g++ -std=c++20 -Wall -Wextra -pedantic -O2 `
    main.cpp route.cpp checkpoint.cpp smartroute.cpp -o $outBin

& .\$outBin | Out-File -Encoding utf8 $outTxt

fc.exe minta-stdout.txt $outTxt
if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "Az ellenorzes sikeres: a kimenet egyezik."
} else {
    Write-Host ""
    Write-Host "Elteres van a vart kimenethez kepest."
    exit 1
}
