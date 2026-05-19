/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
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
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  code *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte bStack_42;
  byte abStack_41 [13];
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  bVar4 = *(char *)(iVar3 + 0x8e) * '\t' + *(char *)(iVar3 + 0x90);
  while (*(char *)(iVar3 + 0x92) != '\0') {
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = (uint)bVar4 * 0xe;
    if (-1 < *(short *)(iVar8 + iVar5)) break;
    iVar10 = iVar5 + 2;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar8 + iVar10);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar11 = (uint)*(ushort *)(iVar5 + 4 + iVar8);
    if ((uVar2 & 3) == 3) {
      (**(code **)(_r_ip_funcs_p + 0xf8))(uVar11,*(code **)(_r_ip_funcs_p + 0xf8));
      pcVar9 = *(code **)(_r_modules_funcs_p + 0xe4);
      uVar7 = 0x20c;
_L457:
      (*pcVar9)(uVar7,param_1 << 8 | 1,0xff,pcVar9);
    }
    else if ((uVar2 & 3) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xb42,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar6 = (uint)(*(ushort *)(iVar5 + iVar10) >> 8);
      if (uVar6 < 5) {
        if (uVar6 == 0) goto _L433;
      }
      else if ((*(ushort *)(iVar3 + 0x84) & 0x40) != 0) {
        uVar6 = uVar6 - 4 & 0xffff;
      }
      iVar5 = *(int *)(iVar3 + 0x28);
      if (iVar5 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xb22,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((*(ushort *)(iVar5 + 6) & 0x3ff) + (uint)*(ushort *)(iVar5 + 4) <= uVar11 + uVar6) {
        (**(code **)(_r_modules_funcs_p + 0x40))(iVar3 + 0x28,*(code **)(_r_modules_funcs_p + 0x40))
        ;
        if (*(int *)(iVar3 + 0x30) == iVar5) {
          *(undefined4 *)(iVar3 + 0x30) = 0;
        }
        (**(code **)(_r_ip_funcs_p + 0xd0))
                  (*(undefined2 *)(iVar5 + 4),*(code **)(_r_ip_funcs_p + 0xd0));
        pcVar9 = *(code **)(_r_modules_funcs_p + 0xe4);
        uVar7 = 0x20e;
        goto _L457;
      }
    }
_L433:
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar5 + iVar10);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar10) = uVar2 & 0xffef;
    cVar1 = *(char *)(iVar3 + 0x92);
    *(char *)(iVar3 + 0x92) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bVar4 = *(byte *)(iVar3 + 0x8e);
      bStack_42 = 0;
      abStack_41[0] = 0;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = (uint)bVar4 * 0x5a;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (*(ushort *)(iVar5 + iVar8) & 0x1f,&bStack_42,abStack_41,
                 *(code **)(_r_modules_funcs_p + 0x1e0));
      uVar11 = (uint)bStack_42;
      uVar12 = (uint)rwip_coex_cfg;
      uVar6 = (uint)abStack_41[0];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar5 + iVar8);
      if ((uVar11 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar6 << 6 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar8) =
           (ushort)(uVar11 << 7) | (ushort)(uVar6 << 6) | (ushort)((uVar12 & 1) << 10) |
           (ushort)((uVar12 & 2) << 8) | (ushort)((uVar12 & 4) << 6) | uVar2 & 0x1f;
    }
    bVar4 = *(char *)(iVar3 + 0x90) + 1U & 1;
    *(byte *)(iVar3 + 0x90) = bVar4;
    bVar4 = bVar4 + *(char *)(iVar3 + 0x8e) * '\t';
  }
  *(ushort *)(iVar3 + 0x84) =
       (ushort)(*(char *)(iVar3 + 0x92) != '\0') << 3 | *(ushort *)(iVar3 + 0x84) & 0xfff7;
  return;
}

