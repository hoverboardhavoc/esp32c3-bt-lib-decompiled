/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_param_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_param_update
          (uint param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,uint param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(short *)(iVar1 + 0x40) = (short)(param_2 << 2);
      *(short *)(iVar1 + 0x3c) = (short)(param_3 << 2);
      *(int *)(iVar1 + 0x38) = param_6 << 5;
      *(undefined1 *)(iVar1 + 0x46) = 1;
      *(short *)(iVar1 + 0x44) = (short)param_7;
      *(int *)(iVar1 + 0x34) = param_4 << 2;
      *(short *)(iVar1 + 0x3e) = (short)param_5;
      if (((uint)(param_4 << 2) < *(uint *)(iVar1 + 100)) && (1 < *(byte *)(iVar1 + 0x94))) {
        r_lld_con_tx_len_update(param_1);
      }
    }
    else {
      r_assert_param(0,"lld_con.c",0x1058);
    }
    *(undefined2 *)(iVar1 + 0x42) = 0;
    r_ble_log_internal_x4
              (0x40a30119,param_4 << 0x10 | param_3,param_6 << 0x10 | param_5,
               (uint)*(ushort *)(iVar1 + 0x7c) << 0x10 | param_7,param_2 << 8 | param_1);
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

