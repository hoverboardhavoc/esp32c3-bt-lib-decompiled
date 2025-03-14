/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  byte bStack_42;
  byte abStack_41 [13];
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  bVar3 = *(char *)(iVar5 + 0x8e) * '\t' + *(char *)(iVar5 + 0x90);
  uVar9 = (uint)rwip_coex_cfg;
  while (*(char *)(iVar5 + 0x92) != '\0') {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = (uint)bVar3 * 0xe;
    if (-1 < *(short *)(iVar6 + iVar4)) break;
    iVar10 = iVar4 + 2;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar10);
    uVar12 = uVar2 & 3;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar11 = (uint)*(ushort *)(iVar4 + 4 + iVar6);
    if ((uVar2 & 3) == 0) {
_L406:
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x9c7,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      if (uVar12 < 3) {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar13 = (uint)(*(ushort *)(iVar4 + iVar10) >> 8);
        if (uVar13 < 5) {
          if (uVar13 == 0) goto _L408;
        }
        else if ((*(ushort *)(iVar5 + 0x84) & 0x40) != 0) {
          uVar13 = uVar13 - 4 & 0xffff;
        }
        iVar4 = *(int *)(iVar5 + 0x28);
        if (iVar4 == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x9a7,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar13 + uVar11 < (*(ushort *)(iVar4 + 6) & 0x3ff) + (uint)*(ushort *)(iVar4 + 4))
        goto _L408;
        (**(code **)(_r_modules_funcs_p + 0x40))(iVar5 + 0x28,*(code **)(_r_modules_funcs_p + 0x40))
        ;
        if (*(int *)(iVar5 + 0x30) == iVar4) {
          *(undefined4 *)(iVar5 + 0x30) = 0;
        }
        (**(code **)(_r_ip_funcs_p + 0xd0))
                  (*(undefined2 *)(iVar4 + 4),*(code **)(_r_ip_funcs_p + 0xd0));
        pcVar8 = *(code **)(_r_modules_funcs_p + 0xe4);
        uVar7 = 0x20e;
      }
      else {
        if (uVar12 != 3) goto _L406;
        (**(code **)(_r_ip_funcs_p + 0xf8))(uVar11,*(code **)(_r_ip_funcs_p + 0xf8));
        pcVar8 = *(code **)(_r_modules_funcs_p + 0xe4);
        uVar7 = 0x20c;
      }
      (*pcVar8)(uVar7,param_1 << 8 | 1,0xff,pcVar8);
    }
_L408:
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar10);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar10) = uVar2 & 0xffef;
    cVar1 = *(char *)(iVar5 + 0x92);
    *(char *)(iVar5 + 0x92) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bVar3 = *(byte *)(iVar5 + 0x8e);
      bStack_42 = 0;
      abStack_41[0] = 0;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = (uint)bVar3 * 0x5a;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (*(ushort *)(iVar4 + iVar6) & 0x1f,&bStack_42,abStack_41,
                 *(code **)(_r_modules_funcs_p + 0x1e0));
      uVar11 = (uint)bStack_42;
      uVar13 = (uint)abStack_41[0];
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar6);
      if ((uVar11 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar13 << 6 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar6) =
           (ushort)(uVar11 << 7) | (ushort)(uVar13 << 6) | (ushort)((uVar9 & 1) << 10) |
           (ushort)((uVar9 & 2) << 8) | (ushort)((uVar9 & 4) << 6) | uVar2 & 0x1f;
    }
    bVar3 = *(char *)(iVar5 + 0x90) + 1U & 1;
    *(byte *)(iVar5 + 0x90) = bVar3;
    bVar3 = bVar3 + *(char *)(iVar5 + 0x8e) * '\t';
  }
  *(ushort *)(iVar5 + 0x84) =
       *(ushort *)(iVar5 + 0x84) & 0xfff7 | (ushort)(*(char *)(iVar5 + 0x92) != '\0') << 3;
  return;
}

