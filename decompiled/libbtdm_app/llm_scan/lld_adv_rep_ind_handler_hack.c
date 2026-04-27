/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_scan.o -> lld_adv_rep_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_adv_rep_ind_handler_hack(char *param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  void *pvVar10;
  undefined1 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  byte bVar14;
  ushort uVar15;
  ushort uVar16;
  byte bVar17;
  uint __n;
  byte *pbVar18;
  ushort uStack_62;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar13 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar13 + 0x23) == '\0') {
    return 0;
  }
  bVar14 = (&co_rate_to_phy)[(byte)param_1[0x19]];
  uVar5 = (ushort)(byte)param_1[0x17];
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  pbVar18 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)(byte)param_1[0x14] * 0x44);
  uStack_44 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  bVar6 = 0;
  if (uVar5 != 0xff) {
    uStack_62 = *(ushort *)(param_1 + 2);
    uVar8 = 0;
    if (((((param_1[0x15] & 4U) != 0) && (uVar8 = (uint)(byte)param_1[0x13], uVar8 != 0)) &&
        (uVar8 = 0, *param_1 == '\0')) && (uVar8 = (uint)(byte)param_1[1], uVar8 != 0)) {
      uVar8 = lld_priv_rpa_res(param_1 + 4,param_1 + 10,&uStack_62);
    }
    uVar7 = 0;
    if (uStack_62 != 0) {
      uVar7 = (uStack_62 - 0xc60) / 0x34 & 0xff;
    }
    if (uVar8 != 0) {
      iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar5 = *(ushort *)(uVar7 * 0x34 + iVar13) & 1 | 2;
      memcpy(&uStack_50,param_1 + 4,6);
    }
    if (uStack_62 == 0) {
      memcpy(&uStack_60,param_1 + 4,6);
    }
    else {
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar13 = uVar7 * 0x34;
      if ((*(ushort *)(iVar9 + iVar13) >> 1 & 1) != 0) {
        pvVar10 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                    (uStack_62 + 0x18,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_60,pvVar10,6);
      }
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar9 + iVar13) >> 7 & 1) != 0) {
        pvVar10 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                    (uStack_62 + 0x2e,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_58,pvVar10,6);
      }
      if ((*param_1 != '\0') || ((param_1[0x15] & 6U) != 4)) {
        iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar9 + iVar13) >> 3 & 1) != 0) {
          pvVar10 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                      (uStack_62 + 0x12,*(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(&uStack_50,pvVar10,6);
        }
        iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if (((*(ushort *)(iVar9 + iVar13) >> 3 & 1) != 0) ||
           (iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
           (*(ushort *)(iVar9 + iVar13) >> 7 & 1) != 0)) {
          iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar5 = *(ushort *)(iVar9 + iVar13) & 1;
          if ((param_1[0x17] == '\x01') && ((param_1[9] & 0xc0U) == 0x40)) {
            uVar5 = uVar5 | 2;
          }
        }
      }
    }
    if ((param_1[0x15] & 4U) == 0) {
_L511:
      bVar6 = 0;
    }
    else if (param_1[1] == '\0') {
      memcpy(&uStack_48,param_1 + 10,6);
      bVar6 = param_1[0x18];
      if (bVar6 == 0) goto _L511;
      if ((param_1[0xf] & 0xc0U) != 0xc0) {
        bVar6 = 0xfe;
      }
    }
    else {
      bVar6 = *pbVar18 & 1;
      if ((param_1[0x18] == '\x01') && ((param_1[0xf] & 0xc0U) == 0x40)) {
        bVar6 = bVar6 | 2;
      }
      memcpy(&uStack_48,(void *)(_p_llm_env + 0xc),6);
    }
  }
  iVar13 = (**(code **)(_r_ip_funcs_p + 0x530))
                     (param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x530));
  if (iVar13 != 0) goto _L517;
  if ((bVar14 & 0xfd) != 1) {
    (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x78b,*(code **)(_r_plf_funcs_p + 8));
  }
  if (((((param_1[0x15] & 4U) != 0) && ((uStack_44._1_1_ & 0xc0) == 0x40)) && (bVar6 == 0xfe)) &&
     (pbVar18[1] < 2)) goto _L517;
  bVar17 = *(byte *)(_p_llm_env + 0xd4);
  if ((bVar17 & 1) != 0) {
    if (bVar14 == 1) {
      uVar8 = (int)(uint)bVar17 >> 2;
    }
    else {
      uVar8 = (int)(uint)bVar17 >> 4;
    }
    if ((uVar8 & 3) == 0) {
      iVar9 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
      iVar13 = _p_llm_env;
      if ((*(char *)(_p_llm_env + 0xd7) == '\x02') && (*(char *)(iVar9 + 8) != '\0')) {
        bVar17 = *(byte *)(_p_llm_env + 0xd4);
        if (((param_1[0x15] & 0x10U) != 0) ||
           (((param_1[0x16] == '\0' && (4 < (byte)param_1[0x20])) &&
            (iVar9 = llm_scan_check_mesh_adv_data
                               ((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)), iVar9 != 0)))
           ) {
          *(byte *)(iVar13 + 0xd4) = bVar17 | 0x40;
          uVar8 = 0;
          goto _L524;
        }
      }
      *(byte *)(iVar13 + 0xd4) = *(byte *)(iVar13 + 0xd4) & 0xbf;
      if (param_1[0x12] == '\0') {
        uVar16 = 0;
        uVar15 = 0xff;
      }
      else {
        uVar15 = *(ushort *)(param_1 + 0x10) >> 0xc;
        uVar16 = *(ushort *)(param_1 + 0x10) & 0xfff;
      }
      uVar8 = (**(code **)(_r_ip_funcs_p + 0x520))
                        (&uStack_60,uVar5,param_1[0x15],uVar15,uVar16,
                         *(undefined2 *)(param_1 + 0x1e),*(code **)(_r_ip_funcs_p + 0x520));
    }
    else {
      uVar8 = (uint)((uVar8 & 3) == 2);
    }
_L524:
    if (param_1[0x16] == '\x01') {
      uVar7 = uVar8 + 1 & 0xff;
    }
    else {
      uVar7 = 0;
      if ((uVar8 == 0) && (uVar7 = 0, param_1[0x16] == '\x02')) {
        if (param_1[0x12] == '\0') {
          uVar16 = 0;
          uVar15 = 0xff;
        }
        else {
          uVar15 = *(ushort *)(param_1 + 0x10) >> 0xc;
          uVar16 = *(ushort *)(param_1 + 0x10) & 0xfff;
        }
        llm_adv_reports_list_remove
                  (&uStack_60,uVar5,param_1[0x15],uVar15,uVar16,*(undefined2 *)(param_1 + 0x1e));
        uVar7 = 0;
      }
    }
    if (bVar14 == 1) {
      bVar17 = *(byte *)(_p_llm_env + 0xd4) & 0xf3;
      bVar14 = (byte)(uVar7 << 2);
    }
    else {
      bVar17 = *(byte *)(_p_llm_env + 0xd4) & 0xcf;
      bVar14 = (byte)(uVar7 << 4);
    }
    *(byte *)(_p_llm_env + 0xd4) = bVar17 | bVar14;
    if (uVar8 != 0) goto _L517;
  }
  iVar13 = (**(code **)(_r_ip_funcs_p + 0x534))
                     (param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x534));
  if (iVar13 == 0) {
    uVar4 = (undefined1)uVar5;
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      if ((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar6 != 0xfe)) {
        puVar11 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x2b);
        *puVar11 = 2;
        puVar11[1] = 1;
        uVar2 = (&adv_evt_prop2type)[(byte)param_1[0x15]];
        puVar11[3] = uVar4;
        puVar11[2] = uVar2;
        memcpy(puVar11 + 4,&uStack_60,6);
        bVar6 = param_1[0x20];
        puVar11[10] = bVar6;
        memcpy(puVar11 + 0xb,(void *)((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
               (uint)bVar6);
        memset(puVar11 + (byte)param_1[0x20] + 0xb,0,0x1f - (byte)param_1[0x20]);
        puVar11[0x2a] = param_1[0x1c];
      }
      else {
        puVar11 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x12);
        *puVar11 = 0xb;
        puVar11[1] = 1;
        cVar1 = param_1[0x1c];
        puVar11[2] = 1;
        puVar11[0x11] = cVar1;
        puVar11[3] = uVar4;
        memcpy(puVar11 + 4,&uStack_60,6);
        puVar11[10] = 1;
        memcpy(puVar11 + 0xb,&uStack_48,6);
      }
      (**(code **)(_r_ip_funcs_p + 0x8c))(puVar11,*(code **)(_r_ip_funcs_p + 0x8c));
    }
    else {
      uVar7 = (uint)(byte)param_1[0x20];
      uVar8 = (uint)(byte)param_1[0x28];
      do {
        __n = uVar7;
        if (0xe5 < uVar7) {
          __n = 0xe5;
        }
        puVar12 = (undefined2 *)
                  (**(code **)(_r_modules_funcs_p + 200))
                            (0x1104,0,0x3e,0x100,*(code **)(_r_modules_funcs_p + 200));
        *puVar12 = 0x10d;
        puVar12[1] = (ushort)(byte)param_1[0x15];
        if ((uVar7 < 0xe6) && ((param_1[0x16] & 0xfcU) != 0)) {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (0x60,"llm_scan.c",0x83d,*(code **)(_r_plf_funcs_p + 0xc));
        }
        uVar5 = 0x20;
        if (uVar7 < 0xe6) {
          uVar5 = (ushort)(byte)param_1[0x16] << 5;
        }
        puVar12[1] = puVar12[1] & 0xff9f | uVar5;
        *(undefined1 *)(puVar12 + 2) = uVar4;
        memcpy((void *)((int)puVar12 + 5),&uStack_60,6);
        *(undefined *)((int)puVar12 + 0xb) = (&co_rate_to_phy)[(byte)param_1[0x19]];
        *(undefined *)(puVar12 + 6) = (&co_rate_to_phy)[(byte)param_1[0x1a]];
        bVar14 = 0xff;
        if (param_1[0x12] != '\0') {
          bVar14 = (byte)((ushort)*(undefined2 *)(param_1 + 0x10) >> 0xc);
        }
        *(byte *)((int)puVar12 + 0xd) = bVar14;
        *(char *)(puVar12 + 7) = param_1[0x1b];
        *(char *)((int)puVar12 + 0xf) =
             (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0x1c];
        uVar3 = *(undefined2 *)(param_1 + 0x1e);
        *(byte *)(puVar12 + 9) = bVar6;
        puVar12[8] = uVar3;
        memcpy((void *)((int)puVar12 + 0x13),&uStack_48,6);
        *(char *)((int)puVar12 + 0x19) = (char)__n;
        memcpy(puVar12 + 0xd,(void *)(*(int *)(param_1 + 0x24) + uVar8),__n);
        memset((void *)(__n + 0x1a + (int)puVar12),0,0xe5 - __n);
        uVar7 = uVar7 - __n & 0xff;
        (**(code **)(_r_ip_funcs_p + 0x8c))(puVar12,*(code **)(_r_ip_funcs_p + 0x8c));
        uVar8 = uVar8 + __n & 0xff;
      } while (uVar7 != 0);
    }
  }
_L517:
  if (param_1[0x20] != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x104))
              (*(undefined2 *)(param_1 + 0x22),*(undefined4 *)(param_1 + 0x24),
               *(code **)(_r_ip_funcs_p + 0x104));
  }
  return 0;
}

