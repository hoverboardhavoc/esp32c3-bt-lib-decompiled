/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> f_lld_adv_rep_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_adv_rep_ind_handler_hack(char *param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  void *pvVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined2 *puVar12;
  byte bVar13;
  ushort uVar14;
  ushort uVar15;
  byte bVar16;
  uint __n;
  byte bVar17;
  uint uVar18;
  int iVar19;
  byte *pbVar20;
  ushort uStack_62;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar13 = (&co_rate_to_phy)[(byte)param_1[0x19]];
  uVar5 = (ushort)(byte)param_1[0x17];
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  pbVar20 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)(byte)param_1[0x14] * 0x44);
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_4c = 0;
  if (uVar5 == 0xff) {
    bVar17 = 0;
    bVar6 = 0;
  }
  else {
    uStack_62 = *(ushort *)(param_1 + 2);
    uVar7 = 0;
    if (((((param_1[0x15] & 4U) != 0) && (uVar7 = (uint)(byte)param_1[0x13], uVar7 != 0)) &&
        (uVar7 = 0, *param_1 == '\0')) && (uVar7 = (uint)(byte)param_1[1], uVar7 != 0)) {
      uVar7 = lld_priv_rpa_res(param_1 + 4,param_1 + 10,&uStack_62);
    }
    uVar18 = 0;
    if (uStack_62 != 0) {
      uVar18 = (uStack_62 - 0xc60) / 0x34 & 0xff;
    }
    if (uVar7 != 0) {
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar5 = *(ushort *)(uVar18 * 0x34 + iVar8) & 1 | 2;
      memcpy(&uStack_50,param_1 + 4,6);
    }
    if (uStack_62 == 0) {
      memcpy(&uStack_60,param_1 + 4,6);
    }
    else {
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar19 = uVar18 * 0x34;
      if ((*(ushort *)(iVar8 + iVar19) >> 1 & 1) != 0) {
        pvVar9 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (uStack_62 + 0x18,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_60,pvVar9,6);
      }
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar8 + iVar19) >> 7 & 1) != 0) {
        pvVar9 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (uStack_62 + 0x2e,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_58,pvVar9,6);
      }
      if ((*param_1 != '\0') || ((param_1[0x15] & 6U) != 4)) {
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar8 + iVar19) >> 3 & 1) != 0) {
          pvVar9 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (uStack_62 + 0x12,*(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(&uStack_50,pvVar9,6);
        }
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if (((*(ushort *)(iVar8 + iVar19) >> 3 & 1) != 0) ||
           (iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
           (*(ushort *)(iVar8 + iVar19) >> 7 & 1) != 0)) {
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar5 = *(ushort *)(iVar8 + iVar19) & 1;
          if ((param_1[0x17] == '\x01') && ((param_1[9] & 0xc0U) == 0x40)) {
            uVar5 = uVar5 | 2;
          }
        }
      }
    }
    bVar6 = param_1[0x15] & 4;
    bVar17 = 0;
    if ((param_1[0x15] & 4U) != 0) {
      if (param_1[1] == '\0') {
        memcpy(&uStack_48,param_1 + 10,6);
        bVar6 = param_1[0x18];
        bVar17 = uStack_44._1_1_;
        if ((bVar6 != 0) && ((param_1[0xf] & 0xc0U) != 0xc0)) {
          bVar6 = 0xfe;
        }
      }
      else {
        bVar6 = *pbVar20 & 1;
        if ((param_1[0x18] == '\x01') && ((param_1[0xf] & 0xc0U) == 0x40)) {
          bVar6 = bVar6 | 2;
        }
        memcpy(&uStack_48,(void *)(_p_llm_env + 0xc),6);
        bVar17 = uStack_44._1_1_;
      }
    }
  }
  iVar8 = (**(code **)(_r_ip_funcs_p + 0x530))(param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x530))
  ;
  if (iVar8 == 0) {
    if ((bVar13 & 0xfd) != 1) {
      (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x730,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((((param_1[0x15] & 4U) == 0) || ((bVar17 & 0xc0) != 0x40)) || (bVar6 != 0xfe)) ||
       (1 < pbVar20[1])) {
      bVar16 = *(byte *)(_p_llm_env + 0xd4);
      if ((bVar16 & 1) != 0) {
        if (bVar13 == 1) {
          uVar7 = (int)(uint)bVar16 >> 2;
        }
        else {
          uVar7 = (int)(uint)bVar16 >> 4;
        }
        iVar8 = 0;
        if ((uVar7 & 3) == 0) {
          iVar11 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
          iVar19 = _p_llm_env;
          bVar16 = param_1[0x15];
          if (((*(char *)(_p_llm_env + 0xd7) == '\x02') && (*(char *)(iVar11 + 8) != '\0')) &&
             (((bVar16 & 0x10) != 0 ||
              (((param_1[0x16] == '\0' && (4 < (byte)param_1[0x20])) &&
               (iVar11 = llm_scan_check_mesh_adv_data
                                   ((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
               iVar11 != 0)))))) {
            *(byte *)(iVar19 + 0xd4) = *(byte *)(iVar19 + 0xd4) | 0x40;
          }
          else {
            *(byte *)(iVar19 + 0xd4) = *(byte *)(iVar19 + 0xd4) & 0xbf;
            if (param_1[0x12] == '\0') {
              uVar15 = 0;
              uVar14 = 0xff;
            }
            else {
              uVar14 = *(ushort *)(param_1 + 0x10) >> 0xc;
              uVar15 = *(ushort *)(param_1 + 0x10) & 0xfff;
            }
            iVar8 = (**(code **)(_r_ip_funcs_p + 0x520))
                              (&uStack_60,uVar5,bVar16,uVar14,uVar15,*(undefined2 *)(param_1 + 0x1e)
                               ,*(code **)(_r_ip_funcs_p + 0x520));
          }
        }
        else if ((uVar7 & 3) == 2) {
          iVar8 = 1;
        }
        if (param_1[0x16] == '\x01') {
          uVar7 = iVar8 + 1U & 0xff;
        }
        else {
          if ((iVar8 == 0) && (param_1[0x16] == '\x02')) {
            if (param_1[0x12] == '\0') {
              uVar15 = 0;
              uVar14 = 0xff;
            }
            else {
              uVar14 = *(ushort *)(param_1 + 0x10) >> 0xc;
              uVar15 = *(ushort *)(param_1 + 0x10) & 0xfff;
            }
            llm_adv_reports_list_remove
                      (&uStack_60,uVar5,param_1[0x15],uVar14,uVar15,*(undefined2 *)(param_1 + 0x1e))
            ;
          }
          uVar7 = 0;
        }
        if (bVar13 == 1) {
          bVar16 = (byte)(uVar7 << 2);
          bVar13 = *(byte *)(_p_llm_env + 0xd4) & 0xf3;
        }
        else {
          bVar16 = (byte)(uVar7 << 4);
          bVar13 = *(byte *)(_p_llm_env + 0xd4) & 0xcf;
        }
        *(byte *)(_p_llm_env + 0xd4) = bVar16 | bVar13;
        if (iVar8 != 0) goto _L505;
      }
      iVar8 = (**(code **)(_r_ip_funcs_p + 0x534))
                        (param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x534));
      if (iVar8 == 0) {
        uVar4 = (undefined1)uVar5;
        if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
          if ((((param_1[0x15] & 4U) == 0) || ((bVar17 & 0xc0) != 0x40)) || (bVar6 != 0xfe)) {
            puVar10 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x2b);
            *puVar10 = 2;
            puVar10[1] = 1;
            uVar2 = (&adv_evt_prop2type)[(byte)param_1[0x15]];
            puVar10[3] = uVar4;
            puVar10[2] = uVar2;
            memcpy(puVar10 + 4,&uStack_60,6);
            bVar13 = param_1[0x20];
            puVar10[10] = bVar13;
            memcpy(puVar10 + 0xb,(void *)((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
                   (uint)bVar13);
            memset(puVar10 + (byte)param_1[0x20] + 0xb,0,0x1f - (byte)param_1[0x20]);
            puVar10[0x2a] = param_1[0x1c];
          }
          else {
            puVar10 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x12);
            *puVar10 = 0xb;
            puVar10[1] = 1;
            cVar1 = param_1[0x1c];
            puVar10[2] = 1;
            puVar10[0x11] = cVar1;
            puVar10[3] = uVar4;
            memcpy(puVar10 + 4,&uStack_60,6);
            puVar10[10] = 1;
            uStack_44 = CONCAT11(bVar17,(undefined1)uStack_44);
            memcpy(puVar10 + 0xb,&uStack_48,6);
          }
          (**(code **)(_r_ip_funcs_p + 0x8c))(puVar10,*(code **)(_r_ip_funcs_p + 0x8c));
        }
        else {
          uVar7 = (uint)(byte)param_1[0x20];
          uVar18 = (uint)(byte)param_1[0x28];
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
                        (0x60,"llm_scan.c",0x7e2,*(code **)(_r_plf_funcs_p + 0xc));
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
            bVar13 = 0xff;
            if (param_1[0x12] != '\0') {
              bVar13 = (byte)((ushort)*(undefined2 *)(param_1 + 0x10) >> 0xc);
            }
            *(byte *)((int)puVar12 + 0xd) = bVar13;
            *(char *)(puVar12 + 7) = param_1[0x1b];
            uStack_44 = CONCAT11(bVar17,(undefined1)uStack_44);
            *(char *)((int)puVar12 + 0xf) =
                 (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0x1c];
            uVar3 = *(undefined2 *)(param_1 + 0x1e);
            *(byte *)(puVar12 + 9) = bVar6;
            puVar12[8] = uVar3;
            memcpy((void *)((int)puVar12 + 0x13),&uStack_48,6);
            *(char *)((int)puVar12 + 0x19) = (char)__n;
            memcpy(puVar12 + 0xd,(void *)(*(int *)(param_1 + 0x24) + uVar18),__n);
            memset((void *)(__n + 0x1a + (int)puVar12),0,0xe5 - __n);
            uVar7 = uVar7 - __n & 0xff;
            (**(code **)(_r_ip_funcs_p + 0x8c))(puVar12,*(code **)(_r_ip_funcs_p + 0x8c));
            uVar18 = uVar18 + __n & 0xff;
          } while (uVar7 != 0);
        }
      }
    }
  }
_L505:
  if (param_1[0x20] != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x104))
              (*(undefined2 *)(param_1 + 0x22),*(undefined4 *)(param_1 + 0x24),
               *(code **)(_r_ip_funcs_p + 0x104));
  }
  return 0;
}

