Set WshShell = WScript.CreateObject("WScript.Shell")
do
WScript.Sleep(100)
WshShell.SendKeys("{NUMLOCK}")
WshShell.SendKeys("{CAPSLOCK}")
WScript.Sleep(100)
WshShell.SendKeys("{CAPSLOCK}")
WshShell.SendKeys("{SCROLLLOCK}")
WScript.Sleep(100)
WshShell.SendKeys("{SCROLLLOCK}")
WshShell.SendKeys("{CAPSLOCK}")
WScript.Sleep(100)
WshShell.SendKeys("{CAPSLOCK}")
WshShell.SendKeys("{NUMLOCK}")
loop