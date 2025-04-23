/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined1 *puVar7;
  void *__src;
  undefined1 *puVar8;
  undefined4 uVar9;
  byte bVar10;
  uint uVar11;
  ushort uVar12;
  char cVar13;
  ushort uVar14;
  code *pcVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  ushort uVar19;
  int iVar20;
  uint uVar21;
  undefined4 auStack_44 [4];
  
  iVar17 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar16 = (uint)bVar1 * 0x14;
  uVar12 = *(ushort *)(iVar6 + iVar16 + 2);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar16 + 0x12 + iVar6);
  uVar18 = (uint)uVar2;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x85c))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x85c));
  if (iVar6 != 0) {
    return;
  }
  if ((uVar12 & 0x603d) != 0) goto _L64;
  iVar20 = iVar16 + 4;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar6 + iVar20) & 0xf) != 7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1cf,*(code **)(_r_plf_funcs_p + 8));
  }
  *(undefined4 *)(iVar17 + 0x3c) = *(undefined4 *)(iVar17 + 0x44);
  *(char *)(iVar17 + 100) = *(char *)(iVar17 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar17 + 0x54) = *(char *)(iVar17 + 0x54) + '\x01';
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar12 = *(ushort *)(iVar6 + iVar16 + 0x10);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = uVar12 & 0x3f;
  if (*(ushort *)(iVar6 + iVar20) >> 8 <= uVar4) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1de,*(code **)(_r_plf_funcs_p + 8));
  }
  cVar13 = '\0';
  if ((uVar12 & 0x3f) != 0) {
    cVar13 = (char)uVar4 + -1;
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar14 = (*(ushort *)(iVar6 + iVar20) >> 8) - uVar4 & 0xff;
  puVar7 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x204,0,0xff,0x1c,*(code **)(_r_modules_funcs_p + 200));
  uVar19 = uVar14 - 1 & 0xff;
  *puVar7 = (char)param_1;
  iVar6 = _r_plf_funcs_p;
  uVar11 = *(uint *)(iVar17 + 0x40);
  *(undefined2 *)(puVar7 + 8) = *(undefined2 *)(iVar17 + 0x4a);
  uVar21 = uVar11 >> 1;
  if (*(char *)(iVar17 + 0x57) == '\0') {
    *(undefined1 *)(iVar17 + 0x57) = 1;
    puVar7[1] = *(undefined1 *)(iVar17 + 0x58);
    uVar5 = *(undefined1 *)(iVar17 + 0x59);
    *(short *)(puVar7 + 4) = (short)(uVar11 >> 2);
    puVar7[2] = uVar5;
    uVar11 = *(uint *)(iVar17 + 0x44);
    if (uVar21 == 0) {
      pcVar15 = *(code **)(iVar6 + 8);
      (*pcVar15)(0,0x10000,0x94,pcVar15);
    }
    *(short *)(puVar7 + 6) = (short)((uVar11 >> 1) % uVar21);
    puVar7[10] = *(undefined1 *)(iVar17 + 0x5a);
  }
  else {
    if (param_2 != 0) {
      uVar11 = *(uint *)(iVar17 + 0x44);
      if (uVar21 == 0) {
        pcVar15 = *(code **)(iVar6 + 8);
        (*pcVar15)(0,0x10000,0x94,pcVar15);
      }
      uVar21 = (uVar11 >> 1) % uVar21;
    }
    *(short *)(puVar7 + 6) = (short)uVar21;
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar6 + iVar16 + 0x10);
  uVar21 = (uint)uVar3;
  if ((uVar12 & 0x3f) == 0) {
    *(undefined2 *)(iVar17 + 0x62) = 0;
  }
  else {
    uVar11 = (int)(uVar21 << 0x17) >> 0x1f & 6;
    if ((uVar3 & 0x200) != 0) {
      uVar11 = uVar11 + 6;
    }
    iVar6 = uVar11 + ((uVar3 & 0x400) != 0);
    if ((int)(uVar21 << 0x14) < 0) {
      iVar6 = iVar6 + 2;
    }
    if ((int)(uVar21 << 0x13) < 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (uVar18 + iVar6 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_44,__src,3);
      iVar20 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar20 + iVar16 + 2);
      uVar5 = 2;
      bVar10 = (byte)(uVar12 >> 9) & 1;
      if ((uVar12 >> 9 & 1) == 0) {
        if (*(byte *)(iVar17 + 0x54) < 7) {
          iVar20 = (**(code **)(_r_ip_funcs_p + 0x224))
                             (iVar17 + 0x24,(uint)bVar1,auStack_44[0],
                              *(code **)(_r_ip_funcs_p + 0x224));
          if (iVar20 != 0) {
            uVar5 = 1;
            bVar10 = 1;
            goto _L81;
          }
        }
        uVar5 = 0;
        bVar10 = 2;
      }
_L81:
      *(undefined1 *)(iVar17 + 99) = uVar5;
      *(byte *)(iVar17 + 0x62) = bVar10;
      iVar6 = iVar6 + 3;
    }
    else {
      *(undefined2 *)(iVar17 + 0x62) = 0;
    }
    if ((int)(uVar21 << 0x12) < 0) {
      iVar6 = iVar6 + 0x12;
    }
    if ((int)(uVar21 << 0x11) < 0) {
      uVar21 = uVar18 + iVar6;
      iVar6 = iVar6 + 1;
      puVar8 = (undefined1 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))
                         (uVar21 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      puVar7[0xb] = *puVar8;
    }
    if (param_2 == 0) {
      puVar7[0x19] = 0;
      puVar7[0x1a] = 0;
    }
    else {
      puVar7[0x19] = ((char)uVar4 + -1) - (char)iVar6;
      puVar7[0x1a] = (char)iVar6;
    }
  }
  pcVar15 = _ets_printf;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar5 = (*pcVar15)(*(ushort *)(iVar16 + 6 + iVar6) & 0xff);
  puVar7[0xc] = uVar5;
  uVar12 = *(short *)(iVar17 + 0x52) + uVar19;
  *(ushort *)(iVar17 + 0x52) = uVar12;
  if (0x672 < uVar12) {
    uVar19 = (uVar14 + 0x71) - uVar12 & 0xff;
    *(undefined2 *)(iVar17 + 0x62) = 2;
  }
  puVar7[0xe] = (char)uVar19;
  puVar7[0xd] = *(undefined1 *)(iVar17 + 0x62);
  iVar6 = _r_plf_funcs_p;
  if ((uVar19 != 0) || (puVar7[0x19] != '\0')) {
    *(ushort *)(puVar7 + 0x10) = uVar2;
    uVar9 = (**(code **)(iVar6 + 0xbc))(uVar18,*(code **)(iVar6 + 0xbc));
    iVar6 = _p_lld_env;
    *(undefined4 *)(puVar7 + 0x14) = uVar9;
    puVar7[0x18] = cVar13;
    bVar1 = *(byte *)(iVar6 + 0xd8);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar6) = 0;
  }
  cVar13 = puVar7[0xd];
  if (cVar13 == '\0') {
    cVar13 = '\x03';
_L91:
    (**(code **)(_r_ip_funcs_p + 0x168))(iVar17,cVar13,*(code **)(_r_ip_funcs_p + 0x168));
  }
  else if (cVar13 == '\x02') goto _L91;
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar7,*(code **)(_r_modules_funcs_p + 0xe0));
_L64:
                    /* WARNING: Could not recover jumptable at 0x00010934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x85c))(0,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x85c));
  return;
}

