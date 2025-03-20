/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_process_pkt_rx_pkt_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_pkt_check(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  code *pcVar4;
  ushort uVar5;
  ushort uVar6;
  undefined1 uVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  void *__src;
  undefined1 *puVar12;
  undefined4 uVar13;
  undefined2 uVar14;
  ushort uVar15;
  uint uVar16;
  char cVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  short sVar21;
  undefined4 auStack_44 [4];
  
  iVar20 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar19 = (uint)bVar1 * 0x14;
  uVar15 = *(ushort *)(iVar9 + iVar19 + 2);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar2 = *(short *)(iVar9 + iVar19 + 0x12);
  iVar9 = (**(code **)(_r_ip_funcs_p + 0x85c))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x85c));
  if (iVar9 != 0) {
    return;
  }
  if ((uVar15 & 0x603d) != 0) goto _L73;
  iVar9 = iVar19 + 4;
  iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar10 + iVar9) & 0xf) != 7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x1cf,*(code **)(_r_plf_funcs_p + 8));
  }
  *(undefined4 *)(iVar20 + 0x3c) = *(undefined4 *)(iVar20 + 0x44);
  *(char *)(iVar20 + 100) = *(char *)(iVar20 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar20 + 0x54) = *(char *)(iVar20 + 0x54) + '\x01';
  }
  iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar15 = *(ushort *)(iVar10 + iVar19 + 0x10);
  uVar6 = uVar15 & 0x3f;
  iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if (*(ushort *)(iVar10 + iVar9) >> 8 <= uVar6) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x1de,*(code **)(_r_plf_funcs_p + 8));
  }
  cVar17 = '\0';
  if ((uVar15 & 0x3f) != 0) {
    cVar17 = (char)uVar6 + -1;
  }
  iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar5 = (*(ushort *)(iVar10 + iVar9) >> 8) + ~uVar6 & 0xff;
  puVar11 = (undefined1 *)
            (**(code **)(_r_modules_funcs_p + 200))
                      (0x204,0,0xff,0x1c,*(code **)(_r_modules_funcs_p + 200));
  *puVar11 = (char)param_1;
  *(undefined2 *)(puVar11 + 8) = *(undefined2 *)(iVar20 + 0x4a);
  if (*(char *)(iVar20 + 0x57) == '\0') {
    *(undefined1 *)(iVar20 + 0x57) = 1;
    puVar11[1] = *(undefined1 *)(iVar20 + 0x58);
    puVar11[2] = *(undefined1 *)(iVar20 + 0x59);
    uVar18 = *(uint *)(iVar20 + 0x40);
    *(short *)(puVar11 + 4) = (short)(uVar18 >> 2);
    uVar16 = *(uint *)(iVar20 + 0x44);
    uVar18 = uVar18 >> 1;
    if (uVar18 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x94);
    }
    *(short *)(puVar11 + 6) = (short)((uVar16 >> 1) % uVar18);
    puVar11[10] = *(undefined1 *)(iVar20 + 0x5a);
  }
  else {
    uVar16 = *(uint *)(iVar20 + 0x40) >> 1;
    if (param_2 != 0) {
      uVar18 = *(uint *)(iVar20 + 0x44);
      if (uVar16 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x94);
      }
      uVar16 = (uVar18 >> 1) % uVar16;
    }
    *(short *)(puVar11 + 6) = (short)uVar16;
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar9 + iVar19 + 0x10);
  uVar16 = (uint)uVar3;
  if ((uVar15 & 0x3f) == 0) {
    *(undefined2 *)(iVar20 + 0x62) = 0;
  }
  else {
    sVar21 = 0;
    if ((uVar3 & 0x100) != 0) {
      sVar21 = 6;
    }
    if ((uVar3 & 0x200) != 0) {
      sVar21 = sVar21 + 6;
    }
    if ((uVar3 & 0x400) != 0) {
      sVar21 = sVar21 + 1;
    }
    if ((int)(uVar16 << 0x14) < 0) {
      sVar21 = sVar21 + 2;
    }
    if ((int)(uVar16 << 0x13) < 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (sVar2 + sVar21,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_44,__src,3);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar9 + iVar19 + 2) >> 9 & 1) == 0) {
        if (*(byte *)(iVar20 + 0x54) < 7) {
          iVar9 = (**(code **)(_r_ip_funcs_p + 0x224))
                            (iVar20 + 0x24,(uint)bVar1,auStack_44[0],
                             *(code **)(_r_ip_funcs_p + 0x224));
          uVar14 = 0x101;
          if (iVar9 != 0) goto _L131;
        }
        uVar14 = 2;
      }
      else {
        uVar14 = 0x201;
      }
_L131:
      *(undefined2 *)(iVar20 + 0x62) = uVar14;
      sVar21 = sVar21 + 3;
    }
    else {
      *(undefined2 *)(iVar20 + 0x62) = 0;
    }
    if ((int)(uVar16 << 0x12) < 0) {
      sVar21 = sVar21 + 0x12;
    }
    if ((int)(uVar16 << 0x11) < 0) {
      sVar8 = sVar2 + sVar21;
      sVar21 = sVar21 + 1;
      puVar12 = (undefined1 *)
                (**(code **)(_r_plf_funcs_p + 0xbc))(sVar8,*(code **)(_r_plf_funcs_p + 0xbc));
      puVar11[0xb] = *puVar12;
    }
    if (param_2 == 0) {
      puVar11[0x19] = 0;
      puVar11[0x1a] = 0;
    }
    else {
      puVar11[0x19] = ((char)uVar6 + -1) - (char)sVar21;
      puVar11[0x1a] = (char)sVar21;
    }
  }
  pcVar4 = _rwip_rf;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar7 = (*pcVar4)(*(ushort *)(iVar19 + 6 + iVar9) & 0xff);
  puVar11[0xc] = uVar7;
  uVar15 = *(short *)(iVar20 + 0x52) + uVar5;
  *(ushort *)(iVar20 + 0x52) = uVar15;
  if (0x672 < uVar15) {
    uVar5 = (uVar5 + 0x72) - uVar15 & 0xff;
    *(undefined2 *)(iVar20 + 0x62) = 2;
  }
  puVar11[0xe] = (char)uVar5;
  puVar11[0xd] = *(undefined1 *)(iVar20 + 0x62);
  iVar9 = _r_plf_funcs_p;
  if ((uVar5 != 0) || (puVar11[0x19] != '\0')) {
    *(short *)(puVar11 + 0x10) = sVar2;
    uVar13 = (**(code **)(iVar9 + 0xbc))(sVar2,*(code **)(iVar9 + 0xbc));
    *(undefined4 *)(puVar11 + 0x14) = uVar13;
    puVar11[0x18] = cVar17;
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar9) = 0;
  }
  if (puVar11[0xd] == '\0') {
    uVar13 = 3;
_L101:
    (**(code **)(_r_ip_funcs_p + 0x168))(iVar20,uVar13,*(code **)(_r_ip_funcs_p + 0x168));
  }
  else {
    uVar13 = 2;
    if (puVar11[0xd] == '\x02') goto _L101;
  }
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar11,*(code **)(_r_modules_funcs_p + 0xe0));
_L73:
                    /* WARNING: Could not recover jumptable at 0x00010906. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x85c))(0,param_1,param_2);
  return;
}

