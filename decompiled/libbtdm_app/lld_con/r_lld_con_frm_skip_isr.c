/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_skip_isr(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000132ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xcb4,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  if (1 < (byte)(*(char *)(iVar2 + 0x8f) - 1U)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xc9b,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  if (*(char *)(iVar2 + 0x8f) == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x0001324c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
    return;
  }
  *(uint *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + *(int *)(iVar2 + 100) & 0xfffffff;
  cVar1 = rwip_priority;
  *(short *)(iVar2 + 0x7e) = *(short *)(iVar2 + 0x7e) + 1;
  *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + cVar1;
                    /* WARNING: Could not recover jumptable at 0x00013292. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x3a8))
            (*(undefined1 *)(iVar2 + 0x8e),uVar3,0,*(code **)(_r_ip_funcs_p + 0x3a8));
  return;
}

