/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_adv_rep_ind_handler_hack
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
  uint uVar6;
  int iVar7;
  void *pvVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  byte bVar11;
  ushort uVar12;
  ushort uVar13;
  byte bVar14;
  byte bVar15;
  uint uVar16;
  int iVar17;
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
  
  bVar11 = (&co_rate_to_phy)[(byte)param_1[0x19]];
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
  bVar15 = 0;
  if (uVar5 != 0xff) {
    uStack_62 = *(ushort *)(param_1 + 2);
    uVar6 = 0;
    if (((((param_1[0x15] & 4U) != 0) && (uVar6 = (uint)(byte)param_1[0x13], uVar6 != 0)) &&
        (uVar6 = 0, *param_1 == '\0')) && (uVar6 = (uint)(byte)param_1[1], uVar6 != 0)) {
      uVar6 = lld_priv_rpa_res(param_1 + 4,param_1 + 10,&uStack_62);
    }
    if (uStack_62 == 0) {
      if (uVar6 != 0) {
        uVar16 = 0;
        goto _L547;
      }
_L502:
      memcpy(&uStack_60,param_1 + 4,6);
    }
    else {
      uVar16 = (uStack_62 - 0xc60) / 0x34 & 0xff;
      if (uVar6 != 0) {
_L547:
        iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar5 = *(ushort *)(uVar16 * 0x34 + iVar7);
        memcpy(&uStack_50,param_1 + 4,6);
        uVar5 = uVar5 & 1 | 2;
        if (uStack_62 == 0) goto _L502;
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
      iVar17 = uVar16 * 0x34;
      if ((*(ushort *)(iVar7 + iVar17) >> 1 & 1) != 0) {
        pvVar8 = (void *)r_emi_get_mem_addr_by_offset(uStack_62 + 0x18);
        memcpy(&uStack_60,pvVar8,6);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((*(ushort *)(iVar7 + iVar17) >> 7 & 1) != 0) {
        pvVar8 = (void *)r_emi_get_mem_addr_by_offset(uStack_62 + 0x2e);
        memcpy(&uStack_58,pvVar8,6);
      }
      if ((*param_1 != '\0') || ((param_1[0x15] & 6U) != 4)) {
        iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
        if ((*(ushort *)(iVar7 + iVar17) >> 3 & 1) != 0) {
          pvVar8 = (void *)r_emi_get_mem_addr_by_offset(uStack_62 + 0x12);
          memcpy(&uStack_50,pvVar8,6);
        }
        iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
        if (((*(ushort *)(iVar7 + iVar17) >> 3 & 1) != 0) ||
           (iVar7 = r_emi_get_mem_addr_by_offset(0xc60), (*(ushort *)(iVar7 + iVar17) >> 7 & 1) != 0
           )) {
          iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
          uVar5 = *(ushort *)(iVar7 + iVar17) & 1;
          if ((param_1[0x17] == '\x01') && ((param_1[9] & 0xc0U) == 0x40)) {
            uVar5 = uVar5 | 2;
          }
        }
      }
    }
    if ((param_1[0x15] & 4U) == 0) {
_L515:
      bVar15 = 0;
    }
    else if (param_1[1] == '\0') {
      memcpy(&uStack_48,param_1 + 10,6);
      bVar15 = param_1[0x18];
      if (bVar15 == 0) goto _L515;
      if ((param_1[0xf] & 0xc0U) != 0xc0) {
        bVar15 = 0xfe;
      }
    }
    else {
      bVar15 = *pbVar18 & 1;
      if ((param_1[0x18] == '\x01') && ((param_1[0xf] & 0xc0U) == 0x40)) {
        bVar15 = bVar15 | 2;
      }
      memcpy(&uStack_48,(void *)(_p_llm_env + 0xc),6);
    }
  }
  iVar7 = r_llm_adv_rep_flow_control_check_eco(param_1,&uStack_60);
  if (iVar7 != 0) goto _L521;
  if ((bVar11 & 0xfd) != 1) {
    r_assert_err("llm_scan.c",0x730);
  }
  if (((((param_1[0x15] & 4U) != 0) && ((uStack_44._1_1_ & 0xc0) == 0x40)) && (bVar15 == 0xfe)) &&
     (pbVar18[1] < 2)) goto _L521;
  bVar14 = *(byte *)(_p_llm_env + 0xd4);
  if ((bVar14 & 1) != 0) {
    if (bVar11 == 1) {
      uVar6 = (int)(uint)bVar14 >> 2;
    }
    else {
      uVar6 = (int)(uint)bVar14 >> 4;
    }
    if ((uVar6 & 3) == 0) {
      iVar17 = r_llm_le_scan_duplicate_opt_get();
      iVar7 = _p_llm_env;
      if ((*(char *)(_p_llm_env + 0xd7) == '\x02') && (*(char *)(iVar17 + 8) != '\0')) {
        bVar14 = *(byte *)(_p_llm_env + 0xd4);
        if (((param_1[0x15] & 0x10U) != 0) ||
           (((param_1[0x16] == '\0' && (4 < (byte)param_1[0x20])) &&
            (iVar17 = llm_scan_check_mesh_adv_data
                                ((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)), iVar17 != 0)
            ))) {
          *(byte *)(iVar7 + 0xd4) = bVar14 | 0x40;
          uVar6 = 0;
          goto _L528;
        }
      }
      *(byte *)(iVar7 + 0xd4) = *(byte *)(iVar7 + 0xd4) & 0xbf;
      if (param_1[0x12] == '\0') {
        uVar13 = 0;
        uVar12 = 0xff;
      }
      else {
        uVar12 = *(ushort *)(param_1 + 0x10) >> 0xc;
        uVar13 = *(ushort *)(param_1 + 0x10) & 0xfff;
      }
      uVar6 = r_llm_adv_reports_list_check
                        (&uStack_60,uVar5,param_1[0x15],uVar12,uVar13,
                         *(undefined2 *)(param_1 + 0x1e));
    }
    else {
      uVar6 = (uint)((uVar6 & 3) == 2);
    }
_L528:
    if (param_1[0x16] == '\x01') {
      uVar16 = uVar6 + 1 & 0xff;
    }
    else {
      uVar16 = 0;
      if ((uVar6 == 0) && (uVar16 = 0, param_1[0x16] == '\x02')) {
        if (param_1[0x12] == '\0') {
          uVar13 = 0;
          uVar12 = 0xff;
        }
        else {
          uVar12 = *(ushort *)(param_1 + 0x10) >> 0xc;
          uVar13 = *(ushort *)(param_1 + 0x10) & 0xfff;
        }
        llm_adv_reports_list_remove
                  (&uStack_60,uVar5,param_1[0x15],uVar12,uVar13,*(undefined2 *)(param_1 + 0x1e));
        uVar16 = 0;
      }
    }
    if (bVar11 == 1) {
      bVar14 = *(byte *)(_p_llm_env + 0xd4) & 0xf3;
      bVar11 = (byte)(uVar16 << 2);
    }
    else {
      bVar14 = *(byte *)(_p_llm_env + 0xd4) & 0xcf;
      bVar11 = (byte)(uVar16 << 4);
    }
    *(byte *)(_p_llm_env + 0xd4) = bVar14 | bVar11;
    if (uVar6 != 0) goto _L521;
  }
  iVar7 = r_llm_adv_rep_flow_control_update_eco(param_1,&uStack_60);
  if (iVar7 == 0) {
    uVar4 = (undefined1)uVar5;
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      if ((((param_1[0x15] & 4U) == 0) || ((uStack_44._1_1_ & 0xc0) != 0x40)) || (bVar15 != 0xfe)) {
        puVar9 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x2b);
        *puVar9 = 2;
        puVar9[1] = 1;
        uVar2 = (&adv_evt_prop2type)[(byte)param_1[0x15]];
        puVar9[3] = uVar4;
        puVar9[2] = uVar2;
        memcpy(puVar9 + 4,&uStack_60,6);
        bVar15 = param_1[0x20];
        puVar9[10] = bVar15;
        memcpy(puVar9 + 0xb,(void *)((uint)(byte)param_1[0x28] + *(int *)(param_1 + 0x24)),
               (uint)bVar15);
        memset(puVar9 + (byte)param_1[0x20] + 0xb,0,0x1f - (byte)param_1[0x20]);
        puVar9[0x2a] = param_1[0x1c];
      }
      else {
        puVar9 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
        *puVar9 = 0xb;
        puVar9[1] = 1;
        cVar1 = param_1[0x1c];
        puVar9[2] = 1;
        puVar9[0x11] = cVar1;
        puVar9[3] = uVar4;
        memcpy(puVar9 + 4,&uStack_60,6);
        puVar9[10] = 1;
        memcpy(puVar9 + 0xb,&uStack_48,6);
      }
      r_hci_send_2_host(puVar9);
    }
    else {
      uVar16 = (uint)(byte)param_1[0x20];
      uVar6 = (uint)(byte)param_1[0x28];
      do {
        __n = uVar16;
        if (0xe5 < uVar16) {
          __n = 0xe5;
        }
        puVar10 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x100);
        *puVar10 = 0x10d;
        puVar10[1] = (ushort)(byte)param_1[0x15];
        if ((uVar16 < 0xe6) && ((param_1[0x16] & 0xfcU) != 0)) {
          r_assert_param(0x60,"llm_scan.c",0x7e2);
        }
        uVar5 = 0x20;
        if (uVar16 < 0xe6) {
          uVar5 = (ushort)(byte)param_1[0x16] << 5;
        }
        puVar10[1] = puVar10[1] & 0xff9f | uVar5;
        *(undefined1 *)(puVar10 + 2) = uVar4;
        memcpy((void *)((int)puVar10 + 5),&uStack_60,6);
        *(undefined *)((int)puVar10 + 0xb) = (&co_rate_to_phy)[(byte)param_1[0x19]];
        *(undefined *)(puVar10 + 6) = (&co_rate_to_phy)[(byte)param_1[0x1a]];
        bVar11 = 0xff;
        if (param_1[0x12] != '\0') {
          bVar11 = (byte)((ushort)*(undefined2 *)(param_1 + 0x10) >> 0xc);
        }
        *(byte *)((int)puVar10 + 0xd) = bVar11;
        *(char *)(puVar10 + 7) = param_1[0x1b];
        *(char *)((int)puVar10 + 0xf) =
             (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0x1c];
        uVar3 = *(undefined2 *)(param_1 + 0x1e);
        *(byte *)(puVar10 + 9) = bVar15;
        puVar10[8] = uVar3;
        memcpy((void *)((int)puVar10 + 0x13),&uStack_48,6);
        *(char *)((int)puVar10 + 0x19) = (char)__n;
        memcpy(puVar10 + 0xd,(void *)(*(int *)(param_1 + 0x24) + uVar6),__n);
        memset((void *)(__n + 0x1a + (int)puVar10),0,0xe5 - __n);
        uVar16 = uVar16 - __n & 0xff;
        r_hci_send_2_host(puVar10);
        uVar6 = uVar6 + __n & 0xff;
      } while (uVar16 != 0);
    }
  }
_L521:
  if (param_1[0x20] != '\0') {
    r_ble_util_buf_rx_free(*(undefined2 *)(param_1 + 0x22),*(undefined4 *)(param_1 + 0x24));
  }
  return 0;
}

