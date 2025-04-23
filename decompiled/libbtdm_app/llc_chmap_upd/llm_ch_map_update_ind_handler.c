/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_chmap_upd.o -> llm_ch_map_update_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_ch_map_update_ind_handler(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = param_1 >> 8;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((((uVar1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + uVar1 * 4), iVar2 != 0)) &&
      ((*(byte *)(iVar2 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar2 + 0x42) & 0x100) == 0)) {
    puVar3 = (undefined4 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x10d,param_1,0x10,*(code **)(_r_modules_funcs_p + 200));
    *(undefined1 *)(puVar3 + 1) = 6;
    (**(code **)(_r_ip_funcs_p + 0x684))(uVar1,0,*(code **)(_r_ip_funcs_p + 0x684));
    *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x618);
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
    *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) | 0x100;
  }
  return 0;
}

