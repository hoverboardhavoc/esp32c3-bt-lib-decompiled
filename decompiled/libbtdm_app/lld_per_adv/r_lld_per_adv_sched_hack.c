/*
 * Last changed at upstream commit 43b48d75e7e468c0cccd038721e1184dae6aabac
 * https://github.com/espressif/esp32c3-bt-lib/commit/43b48d75e7e468c0cccd038721e1184dae6aabac
 * Upstream date: 2022-09-30 15:41:54 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(4ec6feee)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_sched_hack(int param_1)

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
    *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + DAT_0001101b;
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  } while (cVar2 != '\0');
                    /* WARNING: Could not recover jumptable at 0x000100e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))("lld_per_adv.c",0x138);
  return;
}

