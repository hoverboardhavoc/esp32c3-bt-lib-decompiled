/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_ch_map_update(uint param_1,void *param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40a30005,(uint)*(byte *)(iVar1 + 0x46) << 8 | param_1,
                   CONCAT22(param_3,*(undefined2 *)(iVar1 + 0x7c)));
      }
    }
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(undefined1 *)(iVar1 + 0x46) = 2;
      *(undefined2 *)(iVar1 + 0x44) = param_3;
      memcpy((void *)(iVar1 + 0x34),param_2,5);
      uVar2 = 0;
      goto _L804;
    }
    r_assert_param(*(char *)(iVar1 + 0x46),0,"lld_con.c",0xf45);
  }
  uVar2 = 0xc;
_L804:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

