/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_sched(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = *(int *)(&lld_per_adv_env + param_1 * 4);
  *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
  *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  while ((iVar3 - *(int *)(iVar1 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  }
  cVar2 = '\x0f';
  do {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar1,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar3 == 0) {
      *(undefined1 *)(iVar1 + 0x53) = 0;
      return;
    }
    cVar2 = cVar2 + -1;
    *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + DAT_0001301b;
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  } while (cVar2 != '\0');
                    /* WARNING: Could not recover jumptable at 0x000100cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))("lld_per_adv.c",0x13e);
  return;
}

