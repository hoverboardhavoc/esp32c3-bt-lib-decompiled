/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_get_scan_backoff_upperlimit_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_get_scan_backoff_upperlimit_cmd_handler(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  code *pcVar4;
  
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd13,4,*(code **)(_r_modules_funcs_p + 200));
  puVar3[1] = param_1;
  *puVar3 = 0;
  uVar2 = ble_ll_scan_upperlimit_getting();
  iVar1 = _r_ip_funcs_p;
  puVar3[2] = (char)uVar2;
  pcVar4 = *(code **)(iVar1 + 0x8c);
  puVar3[3] = (char)((ushort)uVar2 >> 8);
  (*pcVar4)(puVar3,pcVar4);
  return 0;
}

