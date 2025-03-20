/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_param_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_param_update
          (uint param_1,int param_2,int param_3,int param_4,undefined2 param_5,int param_6,
          undefined2 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40a30004,(uint)*(byte *)(iVar1 + 0x46) << 8 | param_1,
                   CONCAT22(param_7,*(undefined2 *)(iVar1 + 0x7c)));
      }
    }
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(undefined1 *)(iVar1 + 0x46) = 1;
      *(undefined2 *)(iVar1 + 0x44) = param_7;
      *(short *)(iVar1 + 0x40) = (short)(param_2 << 2);
      *(short *)(iVar1 + 0x3c) = (short)(param_3 << 2);
      *(int *)(iVar1 + 0x34) = param_4 << 2;
      *(undefined2 *)(iVar1 + 0x3e) = param_5;
      *(int *)(iVar1 + 0x38) = param_6 << 5;
      if (((uint)(param_4 << 2) < *(uint *)(iVar1 + 100)) && (1 < *(byte *)(iVar1 + 0x94))) {
        r_lld_con_tx_len_update(param_1);
      }
    }
    else {
      r_assert_param(0,"lld_con.c",0xf04);
    }
    *(undefined2 *)(iVar1 + 0x42) = 0;
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

