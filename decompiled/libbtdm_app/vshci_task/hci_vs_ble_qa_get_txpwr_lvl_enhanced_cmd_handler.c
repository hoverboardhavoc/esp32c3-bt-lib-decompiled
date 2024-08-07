/*
 * Last changed at upstream commit ef1dfc518572e9cda55f13906e32207b40ee280b
 * https://github.com/espressif/esp32c3-bt-lib/commit/ef1dfc518572e9cda55f13906e32207b40ee280b
 * Upstream date: 2024-08-07 12:57:51 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(f583012)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_get_txpwr_lvl_enhanced_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_get_txpwr_lvl_enhanced_cmd_handler
          (undefined1 param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_3,0xfd13,6,*(code **)(_r_modules_funcs_p + 200));
  puVar2[1] = param_1;
  *puVar2 = 0;
  uVar3 = ble_txpwr_get(*param_2,*(undefined2 *)(param_2 + 1));
  puVar2[3] = (char)((uint)uVar3 >> 8);
  puVar2[4] = (char)((uint)uVar3 >> 0x10);
  iVar1 = _r_ip_funcs_p;
  puVar2[2] = (char)uVar3;
  pcVar4 = *(code **)(iVar1 + 0x8c);
  puVar2[5] = (char)((uint)uVar3 >> 0x18);
  (*pcVar4)(puVar2,pcVar4);
  return 0;
}

