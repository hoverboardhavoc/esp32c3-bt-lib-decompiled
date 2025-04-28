/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar6;
  undefined1 uVar7;
  short sVar8;
  int iVar9;
  undefined1 *puVar10;
  void *__src;
  undefined1 *puVar11;
  undefined4 uVar12;
  byte bVar13;
  ushort uVar14;
  uint uVar15;
  char cVar16;
  ushort uVar17;
  uint uVar18;
  ushort uVar19;
  int iVar20;
  int iVar21;
  short sVar22;
  undefined4 auStack_44 [4];
  
  iVar21 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = (uint)bVar1 * 0x14;
  uVar14 = *(ushort *)(iVar9 + iVar6 + 2);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar2 = *(short *)(iVar6 + 0x12 + iVar9);
  iVar9 = (**(code **)(_r_ip_funcs_p + 0x85c))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x85c));
  if (iVar9 != 0) {
    return;
  }
  if ((uVar14 & 0x603d) != 0) goto _L69;
  iVar20 = iVar6 + 4;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar9 + iVar20) & 0xf) != 7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1cf,*(code **)(_r_plf_funcs_p + 8));
  }
  *(undefined4 *)(iVar21 + 0x3c) = *(undefined4 *)(iVar21 + 0x44);
  *(char *)(iVar21 + 100) = *(char *)(iVar21 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar21 + 0x54) = *(char *)(iVar21 + 0x54) + '\x01';
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar14 = *(ushort *)(iVar9 + iVar6 + 0x10);
  uVar5 = uVar14 & 0x3f;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if (*(ushort *)(iVar9 + iVar20) >> 8 <= uVar5) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1de,*(code **)(_r_plf_funcs_p + 8));
  }
  cVar16 = '\0';
  if ((uVar14 & 0x3f) != 0) {
    cVar16 = (char)uVar5 + -1;
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar17 = (*(ushort *)(iVar9 + iVar20) >> 8) - uVar5 & 0xff;
  uVar19 = uVar17 - 1 & 0xff;
  puVar10 = (undefined1 *)
            (**(code **)(_r_modules_funcs_p + 200))
                      (0x204,0,0xff,0x1c,*(code **)(_r_modules_funcs_p + 200));
  *puVar10 = (char)param_1;
  *(undefined2 *)(puVar10 + 8) = *(undefined2 *)(iVar21 + 0x4a);
  if (*(char *)(iVar21 + 0x57) == '\0') {
    *(undefined1 *)(iVar21 + 0x57) = 1;
    puVar10[1] = *(undefined1 *)(iVar21 + 0x58);
    puVar10[2] = *(undefined1 *)(iVar21 + 0x59);
    uVar18 = *(uint *)(iVar21 + 0x40);
    *(short *)(puVar10 + 4) = (short)(uVar18 >> 2);
    uVar15 = *(uint *)(iVar21 + 0x44);
    uVar18 = uVar18 >> 1;
    if (uVar18 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x94);
    }
    *(short *)(puVar10 + 6) = (short)((uVar15 >> 1) % uVar18);
    puVar10[10] = *(undefined1 *)(iVar21 + 0x5a);
  }
  else {
    uVar15 = *(uint *)(iVar21 + 0x40) >> 1;
    if (param_2 != 0) {
      uVar18 = *(uint *)(iVar21 + 0x44);
      if (uVar15 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x94);
      }
      uVar15 = (uVar18 >> 1) % uVar15;
    }
    *(short *)(puVar10 + 6) = (short)uVar15;
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar9 + iVar6 + 0x10);
  if ((uVar14 & 0x3f) == 0) {
    *(undefined2 *)(iVar21 + 0x62) = 0;
  }
  else {
    sVar22 = 0;
    if ((uVar3 & 0x100) != 0) {
      sVar22 = 6;
    }
    if ((uVar3 & 0x200) != 0) {
      sVar22 = sVar22 + 6;
    }
    if ((uVar3 & 0x400) != 0) {
      sVar22 = sVar22 + 1;
    }
    if ((uVar3 >> 0xb & 1) != 0) {
      sVar22 = sVar22 + 2;
    }
    if ((uVar3 & 0x1000) == 0) {
      *(undefined2 *)(iVar21 + 0x62) = 0;
    }
    else {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (sVar2 + sVar22,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_44,__src,3);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar14 = *(ushort *)(iVar9 + iVar6 + 2);
      uVar7 = 2;
      bVar13 = (byte)(uVar14 >> 9) & 1;
      if ((uVar14 >> 9 & 1) == 0) {
        if ((*(byte *)(iVar21 + 0x54) < 7) &&
           (iVar9 = (**(code **)(_r_ip_funcs_p + 0x224))
                              (iVar21 + 0x24,(uint)bVar1,auStack_44[0],
                               *(code **)(_r_ip_funcs_p + 0x224)), iVar9 != 0)) {
          uVar7 = 1;
          bVar13 = 1;
        }
        else {
          uVar7 = 0;
          bVar13 = 2;
        }
      }
      *(undefined1 *)(iVar21 + 99) = uVar7;
      *(byte *)(iVar21 + 0x62) = bVar13;
      sVar22 = sVar22 + 3;
    }
    if ((uVar3 & 0x2000) != 0) {
      sVar22 = sVar22 + 0x12;
    }
    if ((uVar3 & 0x4000) != 0) {
      sVar8 = sVar2 + sVar22;
      sVar22 = sVar22 + 1;
      puVar11 = (undefined1 *)
                (**(code **)(_r_plf_funcs_p + 0xbc))(sVar8,*(code **)(_r_plf_funcs_p + 0xbc));
      puVar10[0xb] = *puVar11;
    }
    if (param_2 == 0) {
      puVar10[0x19] = 0;
      puVar10[0x1a] = 0;
    }
    else {
      puVar10[0x19] = ((char)uVar5 + -1) - (char)sVar22;
      puVar10[0x1a] = (char)sVar22;
    }
  }
  pcVar4 = _ets_printf;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar7 = (*pcVar4)(*(ushort *)(iVar6 + 6 + iVar9) & 0xff);
  puVar10[0xc] = uVar7;
  uVar14 = *(short *)(iVar21 + 0x52) + uVar19;
  *(ushort *)(iVar21 + 0x52) = uVar14;
  if (0x672 < uVar14) {
    uVar19 = (uVar17 + 0x71) - uVar14 & 0xff;
    *(undefined2 *)(iVar21 + 0x62) = 2;
  }
  puVar10[0xe] = (char)uVar19;
  puVar10[0xd] = *(undefined1 *)(iVar21 + 0x62);
  iVar6 = _r_plf_funcs_p;
  if ((uVar19 != 0) || (puVar10[0x19] != '\0')) {
    *(short *)(puVar10 + 0x10) = sVar2;
    uVar12 = (**(code **)(iVar6 + 0xbc))(sVar2,*(code **)(iVar6 + 0xbc));
    iVar6 = _p_lld_env;
    *(undefined4 *)(puVar10 + 0x14) = uVar12;
    puVar10[0x18] = cVar16;
    bVar1 = *(byte *)(iVar6 + 0xd8);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar6) = 0;
  }
  if (puVar10[0xd] == '\0') {
    uVar12 = 3;
_L96:
    (**(code **)(_r_ip_funcs_p + 0x168))(iVar21,uVar12,*(code **)(_r_ip_funcs_p + 0x168));
  }
  else {
    uVar12 = 2;
    if (puVar10[0xd] == '\x02') goto _L96;
  }
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar10,*(code **)(_r_modules_funcs_p + 0xe0));
_L69:
                    /* WARNING: Could not recover jumptable at 0x0001091e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x85c))(0,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x85c));
  return;
}

