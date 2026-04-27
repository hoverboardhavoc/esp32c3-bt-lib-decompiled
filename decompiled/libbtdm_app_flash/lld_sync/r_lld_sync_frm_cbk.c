/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  bool bVar7;
  int *piVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  char cVar17;
  undefined4 uStack_44;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined1 uStack_34;
  char acStack_31 [9];
  
  iVar12 = r_sdk_config_get_opts();
  if (*(byte *)(iVar12 + 0xd) <= param_2) {
    r_assert_param(param_2,param_3,0x10000,0x499);
  }
  if (param_3 == 2) {
    param_2 = param_2 & 0xff;
    if (*(int *)(&lld_sync_env + param_2 * 4) == 0) {
      r_assert_err(0,0x10000,0x460);
      return;
    }
    iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
    while (iVar9 = r_lld_rxdesc_check_hack(param_2), iVar9 != 0) {
      cVar1 = *(char *)(iVar12 + 99);
      if (*(ushort *)(iVar12 + 0x52) < 0x673) {
        r_lld_sync_process_pkt_rx_aux_sync_ind(param_2);
        r_lld_sync_process_pkt_rx_pkt_check(param_2,cVar1 == '\0');
      }
      r_lld_rxdesc_free();
    }
    return;
  }
  if (param_3 < 3) {
    param_2 = param_2 & 0xff;
    bVar13 = param_3 != 0;
    iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
    if (iVar12 == 0) {
      r_assert_err(0,0x10000,0x448);
      return;
    }
    bVar2 = *(byte *)(iVar12 + 0x55);
    iVar9 = (uint)bVar2 * 0x5a;
    iVar11 = r_emi_get_mem_addr_by_offset(0x400,param_1);
    uVar3 = *(ushort *)(iVar9 + 0x16 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar11 + iVar9 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(ushort *)(iVar11 + iVar9 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = *(undefined2 *)(iVar9 + 0xe + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_44 = CONCAT22(uVar6,*(undefined2 *)(iVar9 + 0xc + iVar11));
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_38 = *(undefined2 *)(iVar9 + 0x22 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_36 = *(undefined2 *)(iVar9 + 0x24 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_34 = (undefined1)*(undefined2 *)(iVar9 + 0x26 + iVar11);
    r_co_nb_good_le_channels(&uStack_38);
    if (*(char *)(iVar12 + 100) == '\0') {
      uVar16 = *(uint *)(iVar12 + 4) * 0x271;
      iVar11 = (int)((ulonglong)*(uint *)(iVar12 + 4) * 0x271 >> 0x20);
      uVar14 = *(int *)(iVar12 + 8) + uVar16;
      bVar7 = uVar14 < uVar16;
    }
    else {
      uVar16 = *(uint *)(iVar12 + 0x44) * 0x271;
      uVar14 = (int)*(short *)(iVar12 + 0x48) + uVar16;
      bVar7 = uVar14 < uVar16;
      iVar11 = (int)((ulonglong)*(uint *)(iVar12 + 0x44) * 0x271 >> 0x20) +
               ((int)*(short *)(iVar12 + 0x48) >> 0x1f);
    }
    r_ble_log_internal_x4
              (0x40450003,uStack_44,((uint)bVar7 + iVar11) * -0x80000000 | uVar14 >> 1,
               *(undefined2 *)(iVar12 + 0x4a),
               (uint)CONCAT11(bVar13,*(undefined1 *)(iVar12 + 0x55)) | (uVar3 & 0x3f) << 0x10 |
               ((uVar4 & 0xc) << 2 | uVar5 & 3) << 0x18);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    r_ble_log_internal_x1(0x4045015f,*(ushort *)(iVar11 + iVar9) & 0x1f | (uint)bVar2 << 0x10);
    r_sch_arb_remove(iVar12,1);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    iVar9 = iVar9 + 0x18;
    if ((*(ushort *)(iVar11 + iVar9) >> 10 & 1) != 0) {
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar11 + iVar9);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar11) = uVar3 & 0xfbff;
      if (*(char *)(iVar12 + 0x62) == '\x01') {
        r_lld_sync_trunc_ind(param_2);
      }
      *(undefined1 *)(iVar12 + 99) = 0;
    }
    r_lld_sync_process_pkt_rx(param_2);
    if (((*(char *)(iVar12 + 99) == '\x02') ||
        ((*(char *)(iVar12 + 100) == '\0' && (*(char *)(iVar12 + 99) == '\x01')))) &&
       (*(char *)(iVar12 + 0x62) == '\x01')) {
      r_lld_sync_trunc_ind(param_2);
      *(undefined1 *)(iVar12 + 99) = 0;
    }
    if (*(char *)(iVar12 + 0x5b) != '\x02') {
r_lld_sync_sched:
      iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
      acStack_31[0] = '\0';
      uStack_44._3_1_ = bVar13;
      do {
        cVar1 = uStack_44._3_1_;
        bVar2 = DAT_00013065;
        cVar17 = co_sca2ppm;
        if (uStack_44._3_1_ != '\0') {
          if (0xff < (uint)*(byte *)(iVar12 + 0x16) + (uint)DAT_00013065) {
            r_assert_err(0,0x10000,0x342);
          }
          cVar17 = bVar2 + *(char *)(iVar12 + 0x16);
        }
        *(char *)(iVar12 + 0x16) = cVar17;
        if (*(char *)(iVar12 + 99) == '\x01') {
          uVar14 = *(uint *)(iVar12 + 0x2c);
          bVar2 = *(byte *)(iVar12 + 0x31);
          iVar9 = (int)*(short *)(iVar12 + 0x28);
          uVar16 = *(uint *)(iVar12 + 0x24);
        }
        else {
          iVar9 = 1;
          if ((((*(char *)(iVar12 + 100) != '\0') && (*(char *)(iVar12 + 0x62) == '\0')) &&
              (*(ushort *)(iVar12 + 0x4c) != 0)) && (iVar9 = -1, cVar1 == '\0')) {
            iVar11 = *(ushort *)(iVar12 + 0x4c) + 1;
            iVar9 = iVar11 * 0x10000 >> 0x10;
            *(short *)(iVar12 + 0x4e) = (short)iVar11 + *(short *)(iVar12 + 0x4a);
          }
          *(short *)(iVar12 + 0x4a) = *(short *)(iVar12 + 0x4a) + (short)iVar9;
          *(uint *)(iVar12 + 0x44) =
               iVar9 * *(int *)(iVar12 + 0x40) + *(int *)(iVar12 + 0x44) & 0xfffffff;
          iVar9 = r_lld_read_clock();
          if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar12 + 0x44)) + iVar9 & 0xfffffff) <
              0x8000001) {
            iVar9 = r_lld_read_clock();
            uVar14 = iVar9 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar12 + 0x44)) & 0xfffffff;
            if (uVar14 != 0) {
              uVar3 = *(ushort *)(iVar12 + 0x4a);
              uVar16 = *(uint *)(iVar12 + 0x40);
              if (((uint)uVar3 - (uint)*(ushort *)(iVar12 + 0x4e) & 0xffff) < 0x7fff) {
                iVar9 = ((uVar16 - 1) + uVar14) / uVar16 << 0x10;
              }
              else {
                iVar9 = ((*(ushort *)(iVar12 + 0x4e) + 1) - (uint)uVar3) * 0x10000;
                *(undefined1 *)(iVar12 + 100) = 0;
              }
              *(ushort *)(iVar12 + 0x4a) = uVar3 + (short)((uint)iVar9 >> 0x10);
              *(uint *)(iVar12 + 0x44) =
                   (iVar9 >> 0x10) * uVar16 + *(int *)(iVar12 + 0x44) & 0xfffffff;
            }
          }
          else {
            r_lld_read_clock();
          }
          if (*(byte *)(iVar12 + 0x57) == 0) {
            uVar14 = *(int *)(iVar12 + 0x40) * 6;
          }
          else {
            uVar14 = *(uint *)(iVar12 + 0x34);
          }
          if (uVar14 < (*(int *)(iVar12 + 0x44) - *(int *)(iVar12 + 0x3c) & 0xfffffffU)) {
            r_ble_log_internal_x4
                      (0x6005015d,*(undefined4 *)(iVar12 + 0x40),
                       (uint)*(ushort *)(iVar12 + 0x4a) | param_2 << 0x10 |
                       (uint)*(byte *)(iVar12 + 0x57) << 0x18);
_L224:
            r_lld_sync_cleanup(param_2,8);
            return;
          }
          iVar9 = r_rwip_active_check();
          uVar14 = 0x14;
          if (iVar9 == 0) {
            uVar14 = (uint)*(ushort *)(_p_lld_env + 0xd4);
          }
          iVar9 = (((uint)((*(int *)(iVar12 + 0x44) - *(int *)(iVar12 + 0x38)) * 0x10) >> 8) *
                  (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar12 + 0x5a) * 2) + uVar14)) / 100 +
                  0x10;
          uVar14 = iVar9 * 2;
          uVar16 = *(int *)(iVar12 + 0x44) - uVar14 / 0x271 & 0xfffffff;
          uVar15 = (uint)*(ushort *)(iVar12 + 0x48) + iVar9 * -2 + (uVar14 / 0x271) * 0x271;
          iVar9 = (int)(uVar15 * 0x10000) >> 0x10;
          if (iVar9 < 0) {
            uVar16 = uVar16 - 1 & 0xfffffff;
            iVar9 = (int)(((uVar15 & 0xffff) + 0x271) * 0x10000) >> 0x10;
          }
          if (*(char *)(iVar12 + 0x57) == '\0') {
            iVar11 = 300;
            if (*(char *)(iVar12 + 0x56) == '\0') {
              iVar11 = 0x1e;
            }
            uVar14 = uVar14 + iVar11;
            if (((uint)(*(int *)(iVar12 + 0x40) * 0x271) >> 1) - 0x96 < uVar14 >> 1) {
              r_ble_log_internal_x3(0x4005015e,(uint)*(ushort *)(iVar12 + 0x4a) | param_2 << 0x10);
              goto _L224;
            }
          }
          bVar2 = *(byte *)(iVar12 + 0x58);
          *(undefined2 *)(iVar12 + 0x52) = 0;
        }
        *(uint *)(iVar12 + 4) = uVar16;
        uVar16 = (uint)_DAT_00013072;
        *(int *)(iVar12 + 8) = iVar9;
        uVar16 = uVar14 * 2 + uVar16 +
                 (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar2 * 2) * 2;
        if (400000 < uVar16) {
          uVar16 = 400000;
        }
        *(uint *)(iVar12 + 0x10) = uVar16;
        r_lld_sync_insert_eco(param_2,(int)&uStack_44 + 3,uVar14,acStack_31);
        if (acStack_31[0] != '\0') {
          return;
        }
      } while( true );
    }
  }
  else {
    if (param_3 != 4) {
      r_assert_param(param_2,param_3,0x10000,0x4af);
      return;
    }
    param_2 = param_2 & 0xff;
    iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
    if (iVar12 == 0) {
      r_assert_err(0,0x10000,0x48c);
      return;
    }
    r_ble_log_internal_x2
              (0x40450160,
               (uint)*(ushort *)(iVar12 + 0x4a) | param_2 << 0x10 |
               (uint)*(byte *)(iVar12 + 99) << 0x18,*(undefined1 *)(iVar12 + 0x5b));
    r_sch_arb_remove(iVar12,1);
    if (*(char *)(iVar12 + 99) == '\x01') {
      r_lld_sync_trunc_ind(param_2);
      *(undefined1 *)(iVar12 + 99) = 0;
    }
    param_2 = (uint)*(byte *)(iVar12 + 0x55);
    if (*(char *)(iVar12 + 0x5b) != '\x02') {
      bVar13 = true;
      goto r_lld_sync_sched;
    }
  }
  piVar8 = (int *)(&lld_sync_env + param_2 * 4);
  if (*piVar8 != 0) {
    r_ble_log_internal_x1(0x40050154,(uint)*(ushort *)(*piVar8 + 0x4a) | param_2 << 0x10);
    puVar10 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar10 = (char)param_2;
    puVar10[1] = 0;
    r_ke_msg_send();
    r_ke_free(*piVar8);
    *piVar8 = 0;
  }
  return;
}

