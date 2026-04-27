/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_aux_adv_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_aux_adv_ind(int param_1,int param_2,char *param_3)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  short *psVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined2 *puVar12;
  byte bVar13;
  undefined1 uVar14;
  int iVar15;
  short sVar16;
  short sVar17;
  uint uVar18;
  uint uVar19;
  undefined4 auStack_44 [4];
  
  iVar15 = param_2 * 0x14;
  iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar2 = *(short *)(iVar15 + 0x12 + iVar7);
  *(ushort *)(iVar6 + 0x36) = (ushort)(byte)param_3[5];
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  *(byte *)(iVar6 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar7 + iVar15 + 6) >> 0xe);
  puVar10 = _lld_scan_sync_env;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    *(undefined1 *)(iVar6 + 0x3d) = 0;
    return;
  }
  if ((*(ushort *)(param_3 + 6) & 0x100) == 0) {
    sVar16 = 0;
    sVar17 = 0;
    if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) &&
        (sVar17 = sVar16, *(char *)(iVar6 + 0x6f) == -1)) && ((_DAT_60031000 >> 10 & 1) != 0)) {
      *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    }
  }
  else {
    if ((param_3[1] == '\0') && (*(char *)(iVar6 + 0x6f) != -1)) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfeff;
    }
    else {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar13 = (byte)(*(ushort *)(iVar15 + 4 + iVar7) >> 6) & 1;
      param_3[8] = bVar13;
      *(byte *)(iVar6 + 0x6f) = bVar13;
      pvVar8 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 ((ushort)(byte)param_3[3] + sVar2,*(code **)(_r_plf_funcs_p + 0xbc)
                                 );
      memcpy((void *)(iVar6 + 0x5c),pvVar8,6);
      if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
          ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_3 + 6) & 0x200) == 0)))
          ) && (iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                  (0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
               (*(ushort *)(iVar15 + 2 + iVar7) >> 0xb & 1) == 0)) {
        *(undefined1 *)(iVar6 + 0x6e) = 0xff;
      }
    }
    sVar17 = 6;
  }
  iVar7 = _r_plf_funcs_p;
  if ((*(ushort *)(param_3 + 6) & 0x200) != 0) {
    if (*(byte *)(iVar6 + 0x6d) == 4) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfdff;
    }
    else {
      *(byte *)(iVar6 + 0x6d) = *(byte *)(iVar6 + 0x6d) | 4;
      iVar7 = (**(code **)(iVar7 + 0xbc))(0x1000,*(code **)(iVar7 + 0xbc));
      *(byte *)(iVar6 + 0x70) = (byte)(*(ushort *)(iVar15 + 4 + iVar7) >> 7) & 1;
      param_3[2] = (char)sVar17;
    }
    sVar17 = sVar17 + 6;
  }
  if ((*(ushort *)(param_3 + 6) & 0x400) != 0) {
    sVar17 = sVar17 + 1;
  }
  if ((*(ushort *)(param_3 + 6) >> 0xb & 1) == 0) {
    *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    return;
  }
  psVar9 = (short *)(**(code **)(_r_plf_funcs_p + 0xbc))
                              (sVar2 + sVar17,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar1 = *(short *)(iVar6 + 0x34) != *psVar9;
  if (bVar1) {
    *(undefined1 *)(iVar6 + 0x6e) = 0xff;
  }
  sVar16 = sVar17 + 2;
  if (*(char *)(iVar6 + 0x6e) == -1) {
    if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) goto _L394;
  }
  else {
    if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) {
      if (((*(byte *)(iVar6 + 0x6d) & 2) == 0) || (*(char *)(iVar6 + 0x39) != '\x01')) {
        *(undefined1 *)(iVar6 + 0x6e) = 0;
        *(undefined1 *)(iVar6 + 0x3d) = 0;
      }
      else {
        *(undefined1 *)(iVar6 + 0x6e) = 0;
        *(undefined1 *)(iVar6 + 0x3d) = 2;
      }
      goto _L394;
    }
    pvVar8 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + sVar16,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(auStack_44,pvVar8,3);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar15 + 2 + iVar7) >> 9 & 1) == 0) {
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x224))
                        (iVar6 + 0x48,param_2,*(code **)(_r_ip_funcs_p + 0x224));
      uVar14 = 1;
      if (iVar7 != 0) goto _L443;
      *(undefined1 *)(iVar6 + 0x6e) = 2;
    }
    else {
      *(undefined4 *)(iVar6 + 0x2c) = auStack_44[0];
      uVar14 = 2;
_L443:
      *(undefined1 *)(iVar6 + 0x3e) = uVar14;
    }
    *(undefined1 *)(iVar6 + 0x3d) = 3;
  }
  sVar16 = sVar17 + 5;
_L394:
  if ((*(ushort *)(param_3 + 6) & 0x2000) != 0) {
    uVar3 = *(ushort *)(iVar6 + 0x68);
    if ((bVar1 || puVar10 == (undefined1 *)0x0) ||
       (iVar7 = (**(code **)(_r_ip_funcs_p + 0x440))
                          (param_1,param_2,*(undefined1 *)(iVar6 + 0x6f),
                           *(undefined4 *)(iVar6 + 0x5c),*(undefined4 *)(iVar6 + 0x60),uVar3 >> 0xc,
                           *(code **)(_r_ip_funcs_p + 0x440)), iVar7 == 0)) {
      puVar12 = (undefined2 *)
                (**(code **)(_r_plf_funcs_p + 0xbc))
                          (sVar16 + sVar2 + 2,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar6 + 0x76) = *puVar12;
    }
    else {
      puVar10 = (undefined1 *)
                (**(code **)(_r_modules_funcs_p + 200))
                          (0x203,0,0xff,0x30,*(code **)(_r_modules_funcs_p + 200));
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x444))
                        (puVar10 + 2,sVar2 + sVar16,*(code **)(_r_ip_funcs_p + 0x444));
      if (iVar7 == 0) {
        if (*(short *)(puVar10 + 2) == 0) {
          *(undefined2 *)(iVar6 + 0x76) = *(undefined2 *)(puVar10 + 6);
        }
        (**(code **)(_r_modules_funcs_p + 0xd8))
                  (puVar10 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
      }
      else {
        *puVar10 = *_lld_scan_sync_env;
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        puVar10[0x1e] = (byte)((ushort)*(undefined2 *)(iVar7 + iVar15 + 6) >> 0xe);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar15 + 10 + iVar7);
        if ((uVar4 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",1000,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar7 = _r_plf_funcs_p;
        *(uint *)(puVar10 + 0x18) = CONCAT22(uVar4,*(undefined2 *)(iVar15 + 8 + iVar11));
        iVar7 = (**(code **)(iVar7 + 0xbc))(0x1000,*(code **)(iVar7 + 0xbc));
        uVar18 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)(byte)puVar10[0x1e] * 2) * -2 +
                 0x270) - (*(ushort *)(iVar15 + 0xc + iVar7) & 0x3ff);
        uVar19 = (int)(uVar18 * 0x10000) >> 0x10;
        if (((DAT_00015090 & 2) != 0) && (((byte)puVar10[0x1e] - 2 & 0xff) < 2)) {
          uVar19 = (int)(((uVar18 & 0xffff) + (uint)_DAT_00015092 * -2) * 0x10000) >> 0x10;
        }
        if (0x751 < (uVar19 + 0x4e1 & 0xffff)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x713,*(code **)(_r_plf_funcs_p + 8));
        }
        for (; (int)uVar19 < 0; uVar19 = (int)(((uVar19 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
          *(uint *)(puVar10 + 0x18) = *(int *)(puVar10 + 0x18) - 1U & 0xfffffff;
        }
        *(short *)(puVar10 + 0x1c) = (short)uVar19;
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        puVar5 = _lld_scan_sync_env;
        *(undefined2 *)(puVar10 + 0x20) = *(undefined2 *)(iVar15 + 0xe + iVar7);
        puVar10[0x1f] = (byte)(uVar3 >> 0xc);
        puVar10[0x22] = puVar5[3];
        memcpy(puVar10 + 0x23,puVar5 + 4,6);
        (**(code **)(_r_modules_funcs_p + 0xe0))(puVar10,*(code **)(_r_modules_funcs_p + 0xe0));
        (**(code **)(_r_modules_funcs_p + 0x110))
                  (_lld_scan_sync_env,*(code **)(_r_modules_funcs_p + 0x110));
        _lld_scan_sync_env = (undefined1 *)0x0;
      }
    }
    sVar16 = sVar16 + 0x12;
  }
  if ((*(ushort *)(param_3 + 6) & 0x4000) != 0) {
    puVar10 = (undefined1 *)
              (**(code **)(_r_plf_funcs_p + 0xbc))(sVar2 + sVar16,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *(undefined1 *)(iVar6 + 0x73) = *puVar10;
  }
  return;
}

