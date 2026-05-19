/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_canceled_cbk_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_canceled_cbk_hack(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (param_1 != 0) {
    uVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    bVar1 = *(byte *)(param_1 + 0x8f);
    bVar2 = *(byte *)(param_1 + 0x8e);
    if ((bVar1 & 0xfd) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                ((uint)bVar2,bVar1,"lld_con.c",0xd15,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(uint *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 100) & 0xfffffff;
    cVar3 = rwip_priority;
    *(short *)(param_1 + 0x7e) = *(short *)(param_1 + 0x7e) + 1;
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar3;
    (**(code **)(_r_ip_funcs_p + 0x3a8))
              (*(undefined1 *)(param_1 + 0x8e),uVar4,0,*(code **)(_r_ip_funcs_p + 0x3a8));
    if ((*(int *)(&lld_con_env + (uint)bVar2 * 4) != 0) && (bVar1 == 2)) {
      *(undefined1 *)(param_1 + 0x8f) = 2;
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00013370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xd29,*(code **)(_r_plf_funcs_p + 8));
  return;
}

