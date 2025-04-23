/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx(int param_1)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  code *pcVar12;
  int iVar13;
  uint uVar14;
  byte bStack_42;
  byte abStack_41 [13];
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  bVar7 = *(char *)(iVar6 + 0x8e) * '\t' + *(char *)(iVar6 + 0x90);
  while (*(char *)(iVar6 + 0x92) != '\0') {
    iVar9 = (uint)bVar7 * 0xe;
    iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    if (-1 < *(short *)(iVar11 + iVar9)) break;
    iVar13 = iVar9 + 2;
    iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar11 + iVar13);
    iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar14 = (uint)*(ushort *)(iVar9 + 4 + iVar11);
    if ((uVar2 & 3) == 3) {
      (**(code **)(_r_ip_funcs_p + 0xf8))(uVar14,*(code **)(_r_ip_funcs_p + 0xf8));
      pcVar12 = *(code **)(_r_modules_funcs_p + 0xe4);
      uVar10 = 0x20c;
_L426:
      (*pcVar12)(uVar10,param_1 << 8 | 1,0xff,pcVar12);
    }
    else if ((uVar2 & 3) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x9e1,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar8 = (uint)(*(ushort *)(iVar9 + iVar13) >> 8);
      if (uVar8 < 5) {
        if (uVar8 == 0) goto _L402;
      }
      else if ((*(ushort *)(iVar6 + 0x84) & 0x40) != 0) {
        uVar8 = uVar8 - 4 & 0xffff;
      }
      iVar9 = *(int *)(iVar6 + 0x28);
      if (iVar9 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x9c1,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((*(ushort *)(iVar9 + 6) & 0x3ff) + (uint)*(ushort *)(iVar9 + 4) <= uVar14 + uVar8) {
        (**(code **)(_r_modules_funcs_p + 0x40))(iVar6 + 0x28,*(code **)(_r_modules_funcs_p + 0x40))
        ;
        if (*(int *)(iVar6 + 0x30) == iVar9) {
          *(undefined4 *)(iVar6 + 0x30) = 0;
        }
        (**(code **)(_r_ip_funcs_p + 0xd0))
                  (*(undefined2 *)(iVar9 + 4),*(code **)(_r_ip_funcs_p + 0xd0));
        pcVar12 = *(code **)(_r_modules_funcs_p + 0xe4);
        uVar10 = 0x20e;
        goto _L426;
      }
    }
_L402:
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar9 + iVar13);
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar9 + iVar13) = uVar2 & 0xffef;
    cVar1 = *(char *)(iVar6 + 0x92);
    *(char *)(iVar6 + 0x92) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bVar7 = *(byte *)(iVar6 + 0x8e);
      bStack_42 = 0;
      abStack_41[0] = 0;
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar11 = (uint)bVar7 * 0x5a;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (*(ushort *)(iVar9 + iVar11) & 0x1f,&bStack_42,abStack_41,
                 *(code **)(_r_modules_funcs_p + 0x1e0));
      bVar5 = abStack_41[0];
      bVar4 = bStack_42;
      bVar3 = rwip_coex_cfg;
      uVar14 = (uint)rwip_coex_cfg;
      bVar7 = rwip_coex_cfg >> 1;
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar9 + iVar11);
      if ((bVar4 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar5 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar9 + iVar11) =
           (ushort)bVar4 << 7 | (ushort)bVar5 << 6 | (ushort)((uVar14 & 1) << 10) |
           (ushort)((bVar7 & 1) << 9) | (ushort)((bVar3 >> 2 & 1) << 8) | uVar2 & 0x1f;
    }
    bVar7 = *(char *)(iVar6 + 0x90) + 1U & 1;
    *(byte *)(iVar6 + 0x90) = bVar7;
    bVar7 = bVar7 + *(char *)(iVar6 + 0x8e) * '\t';
  }
  *(ushort *)(iVar6 + 0x84) =
       (ushort)(*(char *)(iVar6 + 0x92) != '\0') << 3 | *(ushort *)(iVar6 + 0x84) & 0xfff7;
  return;
}

