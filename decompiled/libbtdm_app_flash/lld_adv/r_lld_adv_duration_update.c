/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_duration_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_duration_update(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    r_assert_err(0,"lld_adv.c",0xdf0);
    goto _L1214;
  }
  if ((*(ushort *)(iVar1 + 0x74) & 8) == 0) {
    uVar4 = 0xffffffff;
    if (param_2 != 0) {
      iVar3 = param_2 << 5;
      iVar2 = *(int *)(iVar1 + 4);
      goto _L1218;
    }
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    iVar3 = 0x1000;
_L1218:
    uVar4 = iVar3 + iVar2 & 0xfffffff;
  }
  *(uint *)(iVar1 + 0x58) = uVar4;
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 4) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x4040000c,param_2 << 0x10 | param_1,*(undefined4 *)(iVar1 + 0x58));
    }
  }
_L1214:
                    /* WARNING: Could not recover jumptable at 0x00015b1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

