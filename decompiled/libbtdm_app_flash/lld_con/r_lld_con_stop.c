/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_stop(uint param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x40030002,param_2 << 8 | param_1);
      }
    }
    uVar1 = 0xc;
    if (*(byte *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 3) < 6) {
      r_assert_param(param_1,param_2,"lld_con.c",0x5c7);
      uVar1 = 0xc;
    }
    goto _L265;
  }
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40030001,(uint)*(byte *)(iVar3 + 0x8f) << 0x10 | param_2 << 8 | param_1);
    }
  }
  if (*(char *)(iVar3 + 0x8f) == '\0') {
    if (param_2 != 0) {
      r_sch_arb_remove(iVar3,0);
      r_lld_con_cleanup(param_1,1,0x16);
      uVar1 = 0;
      goto _L265;
    }
_L264:
    *(undefined1 *)(iVar3 + 0x8f) = 2;
  }
  else if (*(char *)(iVar3 + 0x8f) == '\x01') goto _L264;
  uVar1 = 0;
_L265:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

