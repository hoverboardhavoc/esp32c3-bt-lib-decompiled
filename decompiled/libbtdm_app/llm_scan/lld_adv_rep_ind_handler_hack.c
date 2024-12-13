/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
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
  int iVar11;
  undefined1 *puVar12;
  undefined2 *puVar13;
  int iVar14;
  byte bVar15;
  ushort uVar16;
  ushort uVar17;
  byte bVar18;
  uint __n;
  byte *pbVar19;
  ushort uStack_62;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar14 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar14 + 0x23) == '\0') {
    return 0;
  }
  bVar15 = (&co_rate_to_phy)[(byte)param_1[0x19]];
  uVar5 = (ushort)(byte)param_1[0x17];
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  pbVar19 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)(byte)param_1[0x14] * 0x44);
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
      iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar5 = *(ushort *)(iVar14 + uVar7 * 0x34) & 1 | 2;
      memcpy(&uStack_50,param_1 + 4,6);
    }
    if (uStack_62 == 0) {
      memcpy(&uStack_60,param_1 + 4,6);
    }
    else {
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar14 = uVar7 * 0x34;
      if ((*(ushort *)(iVar9 + iVar14) >> 1 & 1) != 0) {
        pvVar10 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                    (uStack_62 + 0x18,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_60,pvVar10,6);
      }
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar9 + iVar14) >> 7 & 1) != 0) {
        pvVar10 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                    (uStack_62 + 0x2e,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_58,pvVar10,6);
      }
      if ((*param_1 != '\0') || ((param_1[0x15] & 6U) != 4)) {
        iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar9 + iVar14) >> 3 & 1) != 0) {
          pvVar10 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                      (uStack_62 + 0x12,*(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(&uStack_50,pvVar10,6);
        }
        iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if (((*(ushort *)(iVar9 + iVar14) >> 3 & 1) != 0) ||
           (iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
           (*(ushort *)(iVar9 + iVar14) >> 7 & 1) != 0)) {
          iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar5 = *(ushort *)(iVar9 + iVar14) & 1;
          if ((param_1[9] & 0xc0U) == 0x40) {
            uVar5 = uVar5 | 2;
          }
        }
      }
    }
    if ((param_1[0x15] & 4U) == 0) {
_L521:
      bVar6 = 0;
    }
    else if (param_1[1] == '\0') {
      memcpy(&uStack_48,param_1 + 10,6);
      bVar6 = param_1[0x18];
      if (bVar6 == 0) goto _L521;
      if ((param_1[0xf] & 0xc0U) != 0xc0) {
        bVar6 = 0xfe;
      }
    }
    else {
      bVar6 = *pbVar19 & 1;
      if ((param_1[0xf] & 0xc0U) == 0x40) {
        bVar6 = bVar6 | 2;
      }
      memcpy(&uStack_48,(void *)(_p_llm_env + 0xc),6);
    }
  }
  iVar14 = (**(code **)(_r_ip_funcs_p + 0x530))
                     (param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x530));
  if (iVar14 != 0) {
    cVar1 = param_1[0x20];
    goto joined_r0x00011fc8;
  }
  if ((bVar15 & 0xfd) != 1) {
    (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x730,*(code **)(_r_plf_funcs_p + 8));
  }
  if (((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar6 != 0xfe)) ||
     (1 < pbVar19[1])) {
    bVar18 = *(byte *)(_p_llm_env + 0xd4);
    if ((bVar18 & 1) != 0) {
      if (bVar15 == 1) {
        uVar8 = (int)(uint)bVar18 >> 2;
      }
      else {
        uVar8 = (int)(uint)bVar18 >> 4;
      }
      iVar14 = 0;
      if ((uVar8 & 3) == 0) {
        iVar11 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
        iVar9 = _p_llm_env;
        if (((*(char *)(_p_llm_env + 0xd7) == '\x02') && (*(char *)(iVar11 + 8) != '\0')) &&
           ((bVar18 = *(byte *)(_p_llm_env + 0xd4), (param_1[0x15] & 0x10U) != 0 ||
            (((param_1[0x16] == '\0' && (4 < (byte)param_1[0x20])) &&
             (iVar11 = llm_scan_check_mesh_adv_data
                                 ((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)), iVar11 != 0
             )))))) {
          *(byte *)(iVar9 + 0xd4) = bVar18 | 0x40;
        }
        else {
          *(byte *)(iVar9 + 0xd4) = *(byte *)(iVar9 + 0xd4) & 0xbf;
          if (param_1[0x12] == '\0') {
            uVar17 = 0;
            uVar16 = 0xff;
          }
          else {
            uVar16 = *(ushort *)(param_1 + 0x10) >> 0xc;
            uVar17 = *(ushort *)(param_1 + 0x10) & 0xfff;
          }
          iVar14 = (**(code **)(_r_ip_funcs_p + 0x520))
                             (&uStack_60,uVar5,param_1[0x15],uVar16,uVar17,
                              *(undefined2 *)(param_1 + 0x1e),*(code **)(_r_ip_funcs_p + 0x520));
        }
      }
      else if ((uVar8 & 3) == 2) {
        iVar14 = 1;
      }
      if (param_1[0x16] == '\x01') {
        iVar9 = (iVar14 != 0) + 1;
      }
      else {
        iVar9 = 0;
        if ((iVar14 == 0) && (iVar9 = 0, param_1[0x16] == '\x02')) {
          if (param_1[0x12] == '\0') {
            uVar17 = 0;
            uVar16 = 0xff;
          }
          else {
            uVar16 = *(ushort *)(param_1 + 0x10) >> 0xc;
            uVar17 = *(ushort *)(param_1 + 0x10) & 0xfff;
          }
          llm_adv_reports_list_remove
                    (&uStack_60,uVar5,param_1[0x15],uVar16,uVar17,*(undefined2 *)(param_1 + 0x1e));
          iVar9 = 0;
        }
      }
      if (bVar15 == 1) {
        bVar15 = *(byte *)(_p_llm_env + 0xd4) & 0xf3;
        bVar18 = (byte)(iVar9 << 2);
      }
      else {
        bVar15 = *(byte *)(_p_llm_env + 0xd4) & 0xcf;
        bVar18 = (byte)(iVar9 << 4);
      }
      *(byte *)(_p_llm_env + 0xd4) = bVar18 | bVar15;
      if (iVar14 != 0) goto _L527;
    }
    iVar14 = (**(code **)(_r_ip_funcs_p + 0x534))
                       (param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x534));
    if (iVar14 == 0) {
      uVar4 = (undefined1)uVar5;
      if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
        if ((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar6 != 0xfe))
        {
          puVar12 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x2b);
          *puVar12 = 2;
          puVar12[1] = 1;
          uVar2 = (&adv_evt_prop2type)[(byte)param_1[0x15]];
          puVar12[3] = uVar4;
          puVar12[2] = uVar2;
          memcpy(puVar12 + 4,&uStack_60,6);
          bVar6 = param_1[0x20];
          puVar12[10] = bVar6;
          memcpy(puVar12 + 0xb,(void *)((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
                 (uint)bVar6);
          memset(puVar12 + (byte)param_1[0x20] + 0xb,0,0x1f - (byte)param_1[0x20]);
          puVar12[0x2a] = param_1[0x1c];
        }
        else {
          puVar12 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x12);
          *puVar12 = 0xb;
          puVar12[1] = 1;
          cVar1 = param_1[0x1c];
          puVar12[2] = 1;
          puVar12[0x11] = cVar1;
          puVar12[3] = uVar4;
          memcpy(puVar12 + 4,&uStack_60,6);
          puVar12[10] = 1;
          memcpy(puVar12 + 0xb,&uStack_48,6);
        }
        (**(code **)(_r_ip_funcs_p + 0x8c))(puVar12,*(code **)(_r_ip_funcs_p + 0x8c));
      }
      else {
        uVar7 = (uint)(byte)param_1[0x20];
        uVar8 = (uint)(byte)param_1[0x28];
        do {
          __n = uVar7;
          if (0xe5 < uVar7) {
            __n = 0xe5;
          }
          puVar13 = (undefined2 *)
                    (**(code **)(_r_modules_funcs_p + 200))
                              (0x1104,0,0x3e,0x100,*(code **)(_r_modules_funcs_p + 200));
          *puVar13 = 0x10d;
          puVar13[1] = (ushort)(byte)param_1[0x15];
          if ((uVar7 < 0xe6) && ((param_1[0x16] & 0xfcU) != 0)) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (0x60,"llm_scan.c",0x7e2,*(code **)(_r_plf_funcs_p + 0xc));
          }
          uVar5 = 0x20;
          if (uVar7 < 0xe6) {
            uVar5 = (ushort)(byte)param_1[0x16] << 5;
          }
          puVar13[1] = puVar13[1] & 0xff9f | uVar5;
          *(undefined1 *)(puVar13 + 2) = uVar4;
          memcpy((void *)((int)puVar13 + 5),&uStack_60,6);
          *(undefined *)((int)puVar13 + 0xb) = (&co_rate_to_phy)[(byte)param_1[0x19]];
          *(undefined *)(puVar13 + 6) = (&co_rate_to_phy)[(byte)param_1[0x1a]];
          bVar15 = 0xff;
          if (param_1[0x12] != '\0') {
            bVar15 = (byte)((ushort)*(undefined2 *)(param_1 + 0x10) >> 0xc);
          }
          *(byte *)((int)puVar13 + 0xd) = bVar15;
          *(char *)(puVar13 + 7) = param_1[0x1b];
          *(char *)((int)puVar13 + 0xf) =
               (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0x1c];
          uVar3 = *(undefined2 *)(param_1 + 0x1e);
          *(byte *)(puVar13 + 9) = bVar6;
          puVar13[8] = uVar3;
          memcpy((void *)((int)puVar13 + 0x13),&uStack_48,6);
          *(char *)((int)puVar13 + 0x19) = (char)__n;
          memcpy(puVar13 + 0xd,(void *)(*(int *)(param_1 + 0x24) + uVar8),__n);
          memset((void *)(__n + 0x1a + (int)puVar13),0,0xe5 - __n);
          uVar7 = uVar7 - __n & 0xff;
          (**(code **)(_r_ip_funcs_p + 0x8c))(puVar13,*(code **)(_r_ip_funcs_p + 0x8c));
          uVar8 = uVar8 + __n & 0xff;
        } while (uVar7 != 0);
      }
    }
  }
_L527:
  cVar1 = param_1[0x20];
joined_r0x00011fc8:
  if (cVar1 != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x104))
              (*(undefined2 *)(param_1 + 0x22),*(undefined4 *)(param_1 + 0x24),
               *(code **)(_r_ip_funcs_p + 0x104));
  }
  return 0;
}

