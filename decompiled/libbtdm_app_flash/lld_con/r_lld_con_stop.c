/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_stop(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 == 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x20) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x40030002,param_2 << 8 | param_1);
      }
    }
    uVar2 = 0xc;
    if (*(byte *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 3) < 6) {
      r_assert_param(param_1,param_2,"lld_con.c",0x5c7);
      uVar2 = 0xc;
    }
    goto _L269;
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar3 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40030001,(uint)*(byte *)(iVar1 + 0x8f) << 0x10 | param_2 << 8 | param_1);
    }
  }
  if (*(char *)(iVar1 + 0x8f) == '\0') {
    if (param_2 == 0) goto _L268;
    r_sch_arb_remove(iVar1,0);
    r_lld_con_cleanup(param_1,1,0x16);
  }
  else if (*(char *)(iVar1 + 0x8f) == '\x01') {
_L268:
    *(undefined1 *)(iVar1 + 0x8f) = 2;
  }
  uVar2 = 0;
_L269:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

