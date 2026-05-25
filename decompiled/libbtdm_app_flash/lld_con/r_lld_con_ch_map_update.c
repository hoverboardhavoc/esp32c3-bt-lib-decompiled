/*
 * Last changed at upstream commit 0a08c4b32f3666003080b662a1a61794da24ff0f
 * https://github.com/espressif/esp32c3-bt-lib/commit/0a08c4b32f3666003080b662a1a61794da24ff0f
 * Upstream date: 2026-05-25 14:11:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(51d9dfde)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_ch_map_update(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(undefined1 *)(iVar1 + 0x46) = 2;
      *(short *)(iVar1 + 0x44) = (short)param_3;
      memcpy((void *)(iVar1 + 0x34),param_2,5);
      uVar2 = 0;
    }
    else {
      r_assert_param(*(char *)(iVar1 + 0x46),0,"lld_con.c",0x10ba);
      uVar2 = 0xc;
    }
    r_ble_log_internal_x2(0x40a3011a,(uint)*(ushort *)(iVar1 + 0x7c) << 0x10 | param_3,param_1);
    r_ble_log_internal_hex(0x40a3011b,5,param_2);
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

