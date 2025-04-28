/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_start_update_filter_policy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_start_update_filter_policy(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *__dest;
  ushort uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = *(int *)(&lld_adv_env + param_1 * 4);
  if (((*(byte *)(param_2 + 0x1e) & 2) != 0) &&
     (uVar3 = (**(code **)(_r_ip_funcs_p + 0x260))
                        (param_2 + 6,*(undefined1 *)(param_2 + 0x1f),
                         *(code **)(_r_ip_funcs_p + 0x260)), uVar3 < 10)) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar4 + uVar3 * 0x34) >> 5 & 1) != 0) {
      iVar9 = 1;
      iVar4 = 1;
      sVar7 = (short)uVar3 * 0x34 + 0xc60;
      uVar6 = 1;
      goto _L91;
    }
    if (((*(ushort *)(iVar9 + 0x74) & 4) != 0) &&
       (iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
       (*(ushort *)(uVar3 * 0x34 + iVar4) >> 1 & 1) != 0)) {
      uVar6 = 1;
      iVar9 = 1;
      iVar4 = 0;
      sVar7 = (short)((uVar3 * 0x34 + 0xc60) * 0x10000 >> 0x10);
      goto _L91;
    }
  }
  if (*(char *)(param_2 + 0x27) == '\0') {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(ushort *)(iVar9 + 0x74) >> 2 ^ 1) & 1;
  }
  iVar9 = 0;
  iVar4 = 0;
  sVar7 = 0;
_L91:
  bVar1 = *(byte *)(param_2 + 0x20);
  bVar2 = *(byte *)(param_2 + 0x27);
  iVar8 = param_1 * 0x5a;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar8 + 0x14 + iVar5) =
       (ushort)bVar1 << 8 | (ushort)bVar2 << 6 | uVar6 | (ushort)(iVar4 << 2) | (ushort)(iVar9 << 1)
  ;
  if (iVar9 == 0) {
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (param_1 * 0x5a + 0x42cU & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,(void *)(param_2 + 6),6);
    bVar1 = *(byte *)(param_2 + 0x1f);
    if ((bVar1 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x79b,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + 0x32 + iVar9) = (ushort)bVar1;
  }
  else {
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar8 + 0x2c + iVar9) = sVar7;
  }
  return;
}

