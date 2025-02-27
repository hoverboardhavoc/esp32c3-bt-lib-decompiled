/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_phys_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_phys_update(uint param_1,int param_2,int param_3,undefined2 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
      r_ble_log_internal_x2
                (0x40a30006,param_2 << 8 | param_3 << 0x10 | param_1,
                 CONCAT22(param_4,*(undefined2 *)(iVar3 + 0x7c)));
    }
    if (*(char *)(iVar3 + 0x46) == '\0') {
      *(undefined1 *)(iVar3 + 0x46) = 3;
      *(undefined2 *)(iVar3 + 0x44) = param_4;
      uVar1 = *(ushort *)(&byte_tx_time + param_2 * 2);
      uVar2 = *(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar3 + 0x94) * 2);
      *(char *)(iVar3 + 0x34) = (char)param_2;
      *(char *)(iVar3 + 0x35) = (char)param_3;
      uVar4 = 0;
      if (uVar2 < uVar1) {
        r_lld_con_tx_len_update(param_1,param_2,*(undefined4 *)(iVar3 + 100));
      }
      goto _L854;
    }
    r_assert_param(*(char *)(iVar3 + 0x46),0,"lld_con.c",0xf90);
  }
  uVar4 = 0xc;
_L854:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar4;
}

