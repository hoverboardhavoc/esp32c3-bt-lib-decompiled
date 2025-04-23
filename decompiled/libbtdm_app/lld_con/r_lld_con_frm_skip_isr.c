/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_skip_isr(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000132ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xc76,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  uVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  if (1 < (byte)(*(char *)(iVar3 + 0x8f) - 1U)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xc5d,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  iVar1 = _r_ip_funcs_p;
  if (*(char *)(iVar3 + 0x8f) == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x00013264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
    return;
  }
  *(uint *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + *(int *)(iVar3 + 100) & 0xfffffff;
  cVar2 = rwip_priority;
  *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + cVar2;
                    /* WARNING: Could not recover jumptable at 0x000132a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x3a8))(*(undefined1 *)(iVar3 + 0x8e),uVar4,0,*(code **)(iVar1 + 0x3a8));
  return;
}

