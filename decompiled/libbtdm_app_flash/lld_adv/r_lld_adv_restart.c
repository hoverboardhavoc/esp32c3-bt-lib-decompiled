/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_restart(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,0x10000,0xe2f);
    goto _L1225;
  }
  *(undefined1 *)(iVar4 + 0x86) = 0;
  *(short *)(iVar4 + 0x78) = (short)param_3;
  if ((*(ushort *)(iVar4 + 0x74) & 8) == 0) {
    uVar3 = 0xffffffff;
    if (param_2 != 0) {
      iVar1 = *(int *)(iVar4 + 4);
      iVar2 = param_2 << 5;
      goto _L1230;
    }
  }
  else {
    iVar2 = *(int *)(iVar4 + 4);
    iVar1 = 0x1000;
_L1230:
    uVar3 = iVar2 + iVar1 & 0xfffffff;
  }
  *(uint *)(iVar4 + 0x58) = uVar3;
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0x28) & 4) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar1 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40000004,param_2 << 0x10 | param_3 << 8 | param_1,*(undefined4 *)(iVar4 + 0x58));
    }
  }
_L1225:
                    /* WARNING: Could not recover jumptable at 0x000162b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

