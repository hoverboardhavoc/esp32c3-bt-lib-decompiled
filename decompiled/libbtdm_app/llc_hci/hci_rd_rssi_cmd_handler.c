/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_hci.o -> hci_rd_rssi_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_rd_rssi_cmd_handler(uint param_1,undefined2 *param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,*param_2,0x1405,6,*(code **)(_r_modules_funcs_p + 200));
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar4 = _r_ip_funcs_p;
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    *puVar2 = 0;
    cVar1 = (**(code **)(iVar4 + 0x388))(param_1,*(code **)(iVar4 + 0x388));
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x4f4))(*(code **)(_r_ip_funcs_p + 0x4f4));
    cVar1 = (char)(iVar4 / 10) + cVar1;
  }
  else {
    *puVar2 = 0xc;
    cVar1 = '\0';
  }
  puVar2[4] = cVar1;
  *(undefined2 *)(puVar2 + 2) = *param_2;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

