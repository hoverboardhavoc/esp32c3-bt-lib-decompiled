/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_restart(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar3 == 0) {
    r_assert_err(0,0x10000,0xec8);
    goto _L1278;
  }
  *(undefined1 *)(iVar3 + 0x86) = 0;
  *(short *)(iVar3 + 0x78) = (short)param_3;
  if ((*(ushort *)(iVar3 + 0x74) & 8) == 0) {
    uVar1 = 0xffffffff;
    if (param_2 != 0) {
      iVar2 = *(int *)(iVar3 + 4);
      iVar4 = param_2 << 5;
      goto _L1282;
    }
  }
  else {
    iVar2 = *(int *)(iVar3 + 4);
    iVar4 = 0x1000;
_L1282:
    uVar1 = iVar4 + iVar2 & 0xfffffff;
  }
  *(uint *)(iVar3 + 0x58) = uVar1;
  r_ble_log_internal_x2(0x400000f2,param_1 << 0x10 | param_3 << 0x18 | param_2);
_L1278:
                    /* WARNING: Could not recover jumptable at 0x000167b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

