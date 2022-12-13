/*
 * Last changed at upstream commit 84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * https://github.com/espressif/esp32c3-bt-lib/commit/84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * Upstream date: 2022-12-13 21:37:30 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3 (edd93b0)
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
  byte bVar4;
  int iVar5;
  uint __n;
  int iVar6;
  void *pvVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  char *__src;
  ushort uVar10;
  byte bVar11;
  ushort uVar12;
  byte bVar13;
  undefined1 uVar14;
  ushort uVar15;
  uint uVar16;
  byte *pbVar17;
  uint uVar18;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar11 = (&co_rate_to_phy)[(byte)param_1[0x19]];
  uVar15 = (ushort)(byte)param_1[0x17];
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  pbVar17 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)(byte)param_1[0x14] * 0x44);
  uStack_44 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  bVar4 = 0;
  if (uVar15 != 0xff) {
    uVar16 = (uint)*(ushort *)(param_1 + 2);
    if (uVar16 == 0) {
      memcpy(&uStack_60,param_1 + 4,6);
    }
    else {
      if (((param_1[0x13] == '\0') || (*param_1 != '\0')) || ((param_1[0x15] & 4U) == 0)) {
        __src = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                  (uVar16 + 0x18 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      }
      else {
        __src = param_1 + 4;
      }
      memcpy(&uStack_60,__src,6);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = ((uVar16 - 0xc60) / 0x34 & 0xff) * 0x34;
      if ((*(ushort *)(iVar6 + iVar5) >> 7 & 1) != 0) {
        pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (uVar16 + 0x2e & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(&uStack_58,pvVar7,6);
      }
      if ((*param_1 != '\0') || ((param_1[0x15] & 6U) != 4)) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar6 + iVar5) >> 3 & 1) != 0) {
          pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (uVar16 + 0x12 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(&uStack_50,pvVar7,6);
        }
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if (((*(ushort *)(iVar6 + iVar5) >> 3 & 1) != 0) ||
           (iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
           (*(ushort *)(iVar6 + iVar5) >> 7 & 1) != 0)) {
          iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar15 = *(ushort *)(iVar6 + iVar5) & 1;
          if ((param_1[9] & 0xc0U) == 0x40) {
            uVar15 = uVar15 | 2;
          }
        }
      }
    }
    bVar4 = 0;
    if ((param_1[0x15] & 4U) != 0) {
      if (param_1[1] == '\0') {
        memcpy(&uStack_48,param_1 + 10,6);
        bVar4 = param_1[0x18];
        if ((bVar4 != 0) && ((param_1[0xf] & 0xc0U) != 0xc0)) {
          bVar4 = 0xfe;
        }
      }
      else {
        bVar4 = *pbVar17 & 1;
        if ((param_1[0xf] & 0xc0U) == 0x40) {
          bVar4 = bVar4 | 2;
        }
        memcpy(&uStack_48,(void *)(_p_llm_env + 0xc),6);
      }
    }
  }
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x530))(param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x530))
  ;
  if (iVar5 != 0) {
    cVar1 = param_1[0x20];
    goto joined_r0x00011948;
  }
  if ((bVar11 & 0xfd) != 1) {
    (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x662,*(code **)(_r_plf_funcs_p + 8));
  }
  if (((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar4 != 0xfe)) ||
     (1 < pbVar17[1])) {
    bVar13 = *(byte *)(_p_llm_env + 0xd4);
    if ((bVar13 & 1) != 0) {
      if (bVar11 == 1) {
        uVar16 = (int)(uint)bVar13 >> 2;
      }
      else {
        uVar16 = (int)(uint)bVar13 >> 4;
      }
      if ((uVar16 & 3) == 0) {
        if (param_1[0x12] == '\0') {
          uVar12 = 0;
          uVar10 = 0xff;
        }
        else {
          uVar10 = *(ushort *)(param_1 + 0x10) >> 0xc;
          uVar12 = *(ushort *)(param_1 + 0x10) & 0xfff;
        }
        iVar5 = (**(code **)(_r_ip_funcs_p + 0x520))
                          (&uStack_60,uVar15,uVar10,uVar12,*(undefined2 *)(param_1 + 0x1e),
                           *(code **)(_r_ip_funcs_p + 0x520));
      }
      else {
        iVar5 = 0;
        if ((uVar16 & 3) == 2) {
          iVar5 = 1;
        }
      }
      iVar6 = 0;
      if (param_1[0x16] == '\x01') {
        iVar6 = (iVar5 != 0) + 1;
      }
      if (bVar11 == 1) {
        bVar13 = *(byte *)(_p_llm_env + 0xd4) & 0xf3;
        bVar11 = (byte)(iVar6 << 2);
      }
      else {
        bVar13 = *(byte *)(_p_llm_env + 0xd4) & 0xcf;
        bVar11 = (byte)(iVar6 << 4);
      }
      *(byte *)(_p_llm_env + 0xd4) = bVar13 | bVar11;
      if (iVar5 != 0) goto _L451;
    }
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x534))
                      (param_1,&uStack_60,*(code **)(_r_ip_funcs_p + 0x534));
    if (iVar5 == 0) {
      uVar14 = (undefined1)uVar15;
      if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
        if ((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar4 != 0xfe))
        {
          puVar8 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x2b);
          *puVar8 = 2;
          puVar8[1] = 1;
          uVar2 = (&adv_evt_prop2type)[(byte)param_1[0x15]];
          puVar8[3] = uVar14;
          puVar8[2] = uVar2;
          memcpy(puVar8 + 4,&uStack_60,6);
          bVar4 = param_1[0x20];
          puVar8[10] = bVar4;
          memcpy(puVar8 + 0xb,(void *)((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
                 (uint)bVar4);
          memset(puVar8 + (byte)param_1[0x20] + 0xb,0,0x1f - (byte)param_1[0x20]);
          puVar8[0x2a] = param_1[0x1c];
        }
        else {
          puVar8 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x12);
          *puVar8 = 0xb;
          puVar8[1] = 1;
          cVar1 = param_1[0x1c];
          puVar8[2] = 1;
          puVar8[0x11] = cVar1;
          puVar8[3] = uVar14;
          memcpy(puVar8 + 4,&uStack_60,6);
          puVar8[10] = 1;
          memcpy(puVar8 + 0xb,&uStack_48,6);
        }
        (**(code **)(_r_ip_funcs_p + 0x8c))(puVar8,*(code **)(_r_ip_funcs_p + 0x8c));
      }
      else {
        uVar18 = (uint)(byte)param_1[0x20];
        uVar16 = (uint)(byte)param_1[0x28];
        do {
          __n = uVar18;
          if (0xe5 < uVar18) {
            __n = 0xe5;
          }
          puVar9 = (undefined2 *)
                   (**(code **)(_r_modules_funcs_p + 200))
                             (0x1104,0,0x3e,0x100,*(code **)(_r_modules_funcs_p + 200));
          *puVar9 = 0x10d;
          puVar9[1] = (ushort)(byte)param_1[0x15];
          if ((uVar18 < 0xe6) && ((param_1[0x16] & 0xfcU) != 0)) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (0x60,"llm_scan.c",0x6f4,*(code **)(_r_plf_funcs_p + 0xc));
          }
          uVar15 = 0x20;
          if (uVar18 < 0xe6) {
            uVar15 = (ushort)(byte)param_1[0x16] << 5;
          }
          puVar9[1] = puVar9[1] & 0xff9f | uVar15;
          *(undefined1 *)(puVar9 + 2) = uVar14;
          memcpy((void *)((int)puVar9 + 5),&uStack_60,6);
          *(undefined *)((int)puVar9 + 0xb) = (&co_rate_to_phy)[(byte)param_1[0x19]];
          *(undefined *)(puVar9 + 6) = (&co_rate_to_phy)[(byte)param_1[0x1a]];
          bVar11 = 0xff;
          if (param_1[0x12] != '\0') {
            bVar11 = (byte)((ushort)*(undefined2 *)(param_1 + 0x10) >> 0xc);
          }
          *(byte *)((int)puVar9 + 0xd) = bVar11;
          *(char *)(puVar9 + 7) = param_1[0x1b];
          *(char *)((int)puVar9 + 0xf) =
               (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0x1c];
          uVar3 = *(undefined2 *)(param_1 + 0x1e);
          *(byte *)(puVar9 + 9) = bVar4;
          puVar9[8] = uVar3;
          memcpy((void *)((int)puVar9 + 0x13),&uStack_48,6);
          *(char *)((int)puVar9 + 0x19) = (char)__n;
          memcpy(puVar9 + 0xd,(void *)(*(int *)(param_1 + 0x24) + uVar16),__n);
          memset((void *)(__n + 0x1a + (int)puVar9),0,0xe5 - __n);
          uVar18 = uVar18 - __n & 0xff;
          (**(code **)(_r_ip_funcs_p + 0x8c))(puVar9,*(code **)(_r_ip_funcs_p + 0x8c));
          uVar16 = uVar16 + __n & 0xff;
        } while (uVar18 != 0);
      }
    }
  }
_L451:
  cVar1 = param_1[0x20];
joined_r0x00011948:
  if (cVar1 != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x104))
              (*(undefined2 *)(param_1 + 0x22),*(undefined4 *)(param_1 + 0x24),
               *(code **)(_r_ip_funcs_p + 0x104));
  }
  return 0;
}

