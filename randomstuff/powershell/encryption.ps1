$ct = [system.Text.Encoding]::UTF8.GetBytes("Write 'Congratulations!'");
[System.IO.MemoryStream] $output = New-Object System.IO.MemoryStream;
$sr = New-Object System.IO.Compression.DeflateStream($output, [System.IO.Compression.CompressionMode]::Compress);
$sr.Write($ct, 0, $ct.Length);
$sr.Close();
$output.Close();
$b64 =  [System.Convert]::ToBase64String($output.ToArray());
Write-Output $b64;
