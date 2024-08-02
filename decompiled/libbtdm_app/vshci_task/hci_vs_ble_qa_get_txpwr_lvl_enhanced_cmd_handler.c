/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_get_txpwr_lvl_enhanced_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vs_ble_qa_get_txpwr_lvl_enhanced_cmd_handler(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  code *pcVar3;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd13,6,*(code **)(_r_modules_funcs_p + 200));
  puVar2[1] = param_1;
  *puVar2 = 1;
  iVar1 = _r_ip_funcs_p;
  puVar2[2] = 0;
  puVar2[3] = 0;
  pcVar3 = *(code **)(iVar1 + 0x8c);
  puVar2[4] = 0;
  puVar2[5] = 0;
  (*pcVar3)(pcVar3);
  return 0;
}

