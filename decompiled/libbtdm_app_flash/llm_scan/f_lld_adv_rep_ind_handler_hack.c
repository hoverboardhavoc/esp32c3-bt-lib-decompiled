/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_adv_rep_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_adv_rep_ind_handler_hack(char *param_1)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  byte bVar5;
  uint uVar6;
  uint __n;
  uint uVar7;
  int iVar8;
  int iVar9;
  void *pvVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined2 *puVar13;
  byte bVar14;
  ushort uVar15;
  ushort uVar16;
  undefined1 uVar17;
  ushort uVar18;
  byte bVar19;
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
  
  bVar14 = (&co_rate_to_phy)[(byte)param_1[0x19]];
  uVar18 = (ushort)(byte)param_1[0x17];
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  pbVar20 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)(byte)param_1[0x14] * 0x44);
  uStack_44 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  bVar19 = 0;
  if (uVar18 != 0xff) {
    uStack_62 = *(ushort *)(param_1 + 2);
    uVar7 = 0;
    if (((((param_1[0x15] & 4U) != 0) && (uVar7 = (uint)(byte)param_1[0x13], uVar7 != 0)) &&
        (uVar7 = 0, *param_1 == '\0')) && (uVar7 = (uint)(byte)param_1[1], uVar7 != 0)) {
      uVar7 = lld_priv_rpa_res(param_1 + 4,param_1 + 10,&uStack_62);
    }
    if (uStack_62 == 0) {
      if (uVar7 != 0) {
        uVar6 = 0;
        goto _L556;
      }
_L511:
      memcpy(&uStack_60,param_1 + 4,6);
    }
    else {
      uVar6 = (uStack_62 - 0xc60) / 0x34 & 0xff;
      if (uVar7 != 0) {
_L556:
        iVar8 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar18 = *(ushort *)(iVar8 + uVar6 * 0x34);
        memcpy(&uStack_50,param_1 + 4,6);
        uVar18 = uVar18 & 1 | 2;
        if (uStack_62 == 0) goto _L511;
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0xc60);
      iVar8 = uVar6 * 0x34;
      if ((*(ushort *)(iVar9 + iVar8) >> 1 & 1) != 0) {
        pvVar10 = (void *)r_emi_get_mem_addr_by_offset(uStack_62 + 0x18);
        memcpy(&uStack_60,pvVar10,6);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((*(ushort *)(iVar9 + iVar8) >> 7 & 1) != 0) {
        pvVar10 = (void *)r_emi_get_mem_addr_by_offset(uStack_62 + 0x2e);
        memcpy(&uStack_58,pvVar10,6);
      }
      if ((*param_1 != '\0') || ((param_1[0x15] & 6U) != 4)) {
        iVar9 = r_emi_get_mem_addr_by_offset(0xc60);
        if ((*(ushort *)(iVar9 + iVar8) >> 3 & 1) != 0) {
          pvVar10 = (void *)r_emi_get_mem_addr_by_offset(uStack_62 + 0x12);
          memcpy(&uStack_50,pvVar10,6);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0xc60);
        if (((*(ushort *)(iVar9 + iVar8) >> 3 & 1) != 0) ||
           (iVar9 = r_emi_get_mem_addr_by_offset(0xc60), (*(ushort *)(iVar9 + iVar8) >> 7 & 1) != 0)
           ) {
          iVar9 = r_emi_get_mem_addr_by_offset(0xc60);
          uVar18 = *(ushort *)(iVar9 + iVar8) & 1;
          if ((param_1[0x17] == '\x01') && ((param_1[9] & 0xc0U) == 0x40)) {
            uVar18 = uVar18 | 2;
          }
        }
      }
    }
    if ((param_1[0x15] & 4U) == 0) {
_L524:
      bVar19 = 0;
    }
    else {
      bVar19 = param_1[0x18];
      if (param_1[1] == '\0') {
        memcpy(&uStack_48,param_1 + 10,6);
        if (bVar19 == 0) goto _L524;
        if ((param_1[0xf] & 0xc0U) != 0xc0) {
          bVar19 = 0xfe;
        }
      }
      else {
        bVar5 = *pbVar20 & 1;
        bVar1 = bVar19 == 1;
        bVar19 = bVar5;
        if ((bVar1) && ((param_1[0xf] & 0xc0U) == 0x40)) {
          bVar19 = bVar5 | 2;
        }
        memcpy(&uStack_48,(void *)(_p_llm_env + 0xc),6);
      }
    }
  }
  iVar8 = r_llm_adv_rep_flow_control_check_eco(param_1,&uStack_60);
  if (iVar8 == 0) {
    if ((bVar14 & 0xfd) != 1) {
      r_assert_err("llm_scan.c",0x730);
    }
    if (((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar19 != 0xfe)) ||
       (1 < pbVar20[1])) {
      bVar5 = *(byte *)(_p_llm_env + 0xd4);
      if ((bVar5 & 1) != 0) {
        if (bVar14 == 1) {
          uVar7 = (int)(uint)bVar5 >> 2;
        }
        else {
          uVar7 = (int)(uint)bVar5 >> 4;
        }
        iVar8 = 0;
        if ((uVar7 & 3) == 0) {
          iVar12 = r_llm_le_scan_duplicate_opt_get();
          iVar9 = _p_llm_env;
          if (((*(char *)(_p_llm_env + 0xd7) == '\x02') && (*(char *)(iVar12 + 8) != '\0')) &&
             ((bVar5 = *(byte *)(_p_llm_env + 0xd4), (param_1[0x15] & 0x10U) != 0 ||
              (((param_1[0x16] == '\0' && (4 < (byte)param_1[0x20])) &&
               (iVar12 = llm_scan_check_mesh_adv_data
                                   ((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
               iVar12 != 0)))))) {
            *(byte *)(iVar9 + 0xd4) = bVar5 | 0x40;
          }
          else {
            *(byte *)(iVar9 + 0xd4) = *(byte *)(iVar9 + 0xd4) & 0xbf;
            if (param_1[0x12] == '\0') {
              uVar16 = 0;
              uVar15 = 0xff;
            }
            else {
              uVar15 = *(ushort *)(param_1 + 0x10) >> 0xc;
              uVar16 = *(ushort *)(param_1 + 0x10) & 0xfff;
            }
            iVar8 = r_llm_adv_reports_list_check
                              (&uStack_60,uVar18,param_1[0x15],uVar15,uVar16,
                               *(undefined2 *)(param_1 + 0x1e));
          }
        }
        else if ((uVar7 & 3) == 2) {
          iVar8 = 1;
        }
        if (param_1[0x16] == '\x01') {
          iVar9 = (iVar8 != 0) + 1;
        }
        else {
          iVar9 = 0;
          if ((iVar8 == 0) && (iVar9 = 0, param_1[0x16] == '\x02')) {
            if (param_1[0x12] == '\0') {
              uVar16 = 0;
              uVar15 = 0xff;
            }
            else {
              uVar15 = *(ushort *)(param_1 + 0x10) >> 0xc;
              uVar16 = *(ushort *)(param_1 + 0x10) & 0xfff;
            }
            llm_adv_reports_list_remove
                      (&uStack_60,uVar18,param_1[0x15],uVar15,uVar16,*(undefined2 *)(param_1 + 0x1e)
                      );
            iVar9 = 0;
          }
        }
        if (bVar14 == 1) {
          bVar14 = *(byte *)(_p_llm_env + 0xd4) & 0xf3;
          bVar5 = (byte)(iVar9 << 2);
        }
        else {
          bVar14 = *(byte *)(_p_llm_env + 0xd4) & 0xcf;
          bVar5 = (byte)(iVar9 << 4);
        }
        *(byte *)(_p_llm_env + 0xd4) = bVar5 | bVar14;
        if (iVar8 != 0) goto _L530;
      }
      iVar8 = r_llm_adv_rep_flow_control_update_eco(param_1,&uStack_60);
      if (iVar8 == 0) {
        uVar17 = (undefined1)uVar18;
        if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
          if ((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) ||
             (bVar19 != 0xfe)) {
            puVar11 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x2b);
            *puVar11 = 2;
            puVar11[1] = 1;
            uVar3 = (&adv_evt_prop2type)[(byte)param_1[0x15]];
            puVar11[3] = uVar17;
            puVar11[2] = uVar3;
            memcpy(puVar11 + 4,&uStack_60,6);
            bVar14 = param_1[0x20];
            puVar11[10] = bVar14;
            memcpy(puVar11 + 0xb,(void *)((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
                   (uint)bVar14);
            memset(puVar11 + (byte)param_1[0x20] + 0xb,0,0x1f - (byte)param_1[0x20]);
            puVar11[0x2a] = param_1[0x1c];
          }
          else {
            puVar11 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
            *puVar11 = 0xb;
            puVar11[1] = 1;
            cVar2 = param_1[0x1c];
            puVar11[2] = 1;
            puVar11[0x11] = cVar2;
            puVar11[3] = uVar17;
            memcpy(puVar11 + 4,&uStack_60,6);
            puVar11[10] = 1;
            memcpy(puVar11 + 0xb,&uStack_48,6);
          }
          r_hci_send_2_host(puVar11);
        }
        else {
          uVar6 = (uint)(byte)param_1[0x20];
          uVar7 = (uint)(byte)param_1[0x28];
          do {
            __n = uVar6;
            if (0xe5 < uVar6) {
              __n = 0xe5;
            }
            puVar13 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x100);
            *puVar13 = 0x10d;
            puVar13[1] = (ushort)(byte)param_1[0x15];
            if ((uVar6 < 0xe6) && ((param_1[0x16] & 0xfcU) != 0)) {
              r_assert_param(0x60,"llm_scan.c",0x7e2);
            }
            uVar18 = 0x20;
            if (uVar6 < 0xe6) {
              uVar18 = (ushort)(byte)param_1[0x16] << 5;
            }
            puVar13[1] = puVar13[1] & 0xff9f | uVar18;
            *(undefined1 *)(puVar13 + 2) = uVar17;
            memcpy((void *)((int)puVar13 + 5),&uStack_60,6);
            *(undefined *)((int)puVar13 + 0xb) = (&co_rate_to_phy)[(byte)param_1[0x19]];
            *(undefined *)(puVar13 + 6) = (&co_rate_to_phy)[(byte)param_1[0x1a]];
            bVar14 = 0xff;
            if (param_1[0x12] != '\0') {
              bVar14 = (byte)((ushort)*(undefined2 *)(param_1 + 0x10) >> 0xc);
            }
            *(byte *)((int)puVar13 + 0xd) = bVar14;
            *(char *)(puVar13 + 7) = param_1[0x1b];
            *(char *)((int)puVar13 + 0xf) =
                 (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0x1c];
            uVar4 = *(undefined2 *)(param_1 + 0x1e);
            *(byte *)(puVar13 + 9) = bVar19;
            puVar13[8] = uVar4;
            memcpy((void *)((int)puVar13 + 0x13),&uStack_48,6);
            *(char *)((int)puVar13 + 0x19) = (char)__n;
            memcpy(puVar13 + 0xd,(void *)(*(int *)(param_1 + 0x24) + uVar7),__n);
            memset((void *)(__n + 0x1a + (int)puVar13),0,0xe5 - __n);
            uVar6 = uVar6 - __n & 0xff;
            r_hci_send_2_host(puVar13);
            uVar7 = uVar7 + __n & 0xff;
          } while (uVar6 != 0);
        }
      }
    }
  }
_L530:
  if (param_1[0x20] != '\0') {
    r_ble_util_buf_rx_free(*(undefined2 *)(param_1 + 0x22),*(undefined4 *)(param_1 + 0x24));
  }
  return 0;
}

