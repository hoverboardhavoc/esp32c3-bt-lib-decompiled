/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_get_txpwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_get_txpwr_lvl_cmd_handler(undefined1 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  code *pcVar6;
  
  bVar1 = *param_2;
  iVar2 = 4;
  if ((((8 < bVar1) && (iVar2 = 1, bVar1 != 9)) && (iVar2 = 2, bVar1 != 10)) &&
     (iVar2 = 0, bVar1 != 0xb)) {
    iVar2 = 5;
  }
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_3,0xfd13,6,*(code **)(_r_modules_funcs_p + 200));
  uVar5 = 0x12;
  if (iVar2 != 5) {
    uVar5 = 0;
  }
  *puVar3 = uVar5;
  puVar3[1] = param_1;
  uVar4 = ble_txpwr_get(iVar2,0xffff);
  puVar3[3] = (char)((uint)uVar4 >> 8);
  puVar3[4] = (char)((uint)uVar4 >> 0x10);
  iVar2 = _r_ip_funcs_p;
  puVar3[2] = (char)uVar4;
  pcVar6 = *(code **)(iVar2 + 0x8c);
  puVar3[5] = (char)((uint)uVar4 >> 0x18);
  (*pcVar6)(puVar3,pcVar6);
  return 0;
}

