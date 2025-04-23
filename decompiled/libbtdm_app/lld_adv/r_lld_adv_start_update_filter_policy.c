/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  void *__dest;
  ushort uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(&lld_adv_env + param_1 * 4);
  if (((*(byte *)(param_2 + 0x1e) & 2) != 0) &&
     (uVar3 = (**(code **)(_r_ip_funcs_p + 0x260))
                        (param_2 + 6,*(undefined1 *)(param_2 + 0x1f),
                         *(code **)(_r_ip_funcs_p + 0x260)), uVar3 < 10)) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = uVar3 * 0x34;
    if ((*(ushort *)(iVar4 + iVar7) >> 5 & 1) != 0) {
      sVar6 = (short)iVar7 + 0xc60;
      uVar5 = 1;
      iVar4 = 1;
      iVar8 = 1;
      goto _L82;
    }
    if (((*(ushort *)(iVar8 + 0x74) & 4) != 0) &&
       (iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
       (*(ushort *)(iVar4 + iVar7) >> 1 & 1) != 0)) {
      uVar5 = 1;
      iVar4 = 1;
      sVar6 = (short)((uint)((iVar7 + 0xc60) * 0x10000) >> 0x10);
      iVar8 = 0;
      goto _L82;
    }
  }
  if (*(char *)(param_2 + 0x27) == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = (ushort)(*(uint *)(iVar8 + 0x74) >> 2) & 1 ^ 1;
  }
  iVar4 = 0;
  iVar8 = 0;
  sVar6 = 0;
_L82:
  bVar1 = *(byte *)(param_2 + 0x20);
  bVar2 = *(byte *)(param_2 + 0x27);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  param_1 = param_1 * 0x5a;
  *(ushort *)(param_1 + 0x14 + iVar7) =
       (ushort)bVar1 << 8 | (ushort)bVar2 << 6 | uVar5 | (ushort)(iVar8 << 2) | (ushort)(iVar4 << 1)
  ;
  if (iVar4 == 0) {
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(param_1 + 0x42c);
    memcpy(__dest,(void *)(param_2 + 6),6);
    bVar1 = *(byte *)(param_2 + 0x1f);
    if (1 < bVar1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x79b,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(param_1 + 0x32 + iVar8) = (ushort)bVar1;
  }
  else {
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
    *(short *)(param_1 + 0x2c + iVar8) = sVar6;
  }
  return;
}

