/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_phys_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_phys_update(uint param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar2 + 0x28) & 0x20) != 0) &&
       (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
      r_ble_log_internal_x2
                (0x40a30006,param_2 << 8 | param_3 << 0x10 | param_1,
                 CONCAT22(param_4,*(undefined2 *)(iVar1 + 0x7c)));
    }
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(undefined1 *)(iVar1 + 0x46) = 3;
      *(undefined2 *)(iVar1 + 0x44) = param_4;
      *(char *)(iVar1 + 0x34) = (char)param_2;
      *(char *)(iVar1 + 0x35) = (char)param_3;
      uVar3 = 0;
      if (*(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar1 + 0x94) * 2) <
          *(ushort *)(&byte_tx_time + param_2 * 2)) {
        r_lld_con_tx_len_update(param_1,param_2,*(undefined4 *)(iVar1 + 100));
      }
      goto _L823;
    }
    r_assert_param(*(char *)(iVar1 + 0x46),0,"lld_con.c",0xf90);
  }
  uVar3 = 0xc;
_L823:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

