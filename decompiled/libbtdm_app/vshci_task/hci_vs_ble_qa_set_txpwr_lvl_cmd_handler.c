/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_set_txpwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_set_txpwr_lvl_cmd_handler(undefined1 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  bVar1 = *param_2;
  uVar2 = 4;
  if (8 < bVar1) {
    uVar2 = 1;
    if (bVar1 != 9) {
      uVar2 = 2;
      if (bVar1 != 10) {
        uVar2 = 0;
        if (bVar1 != 0xb) {
          uVar2 = 5;
        }
      }
    }
  }
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_3,0xfd13,2,*(code **)(_r_modules_funcs_p + 200));
  *puVar3 = 0;
  iVar4 = ble_txpwr_set(uVar2,0xffff,*(undefined4 *)(param_2 + 1));
  if (iVar4 != 0) {
    *puVar3 = 0x12;
  }
  puVar3[1] = param_1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar3,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

