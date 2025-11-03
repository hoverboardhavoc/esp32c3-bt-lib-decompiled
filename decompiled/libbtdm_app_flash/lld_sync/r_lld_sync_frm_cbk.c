/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char cVar16;
  char acStack_41 [13];
  undefined4 uStack_34;
  
  iVar12 = r_sdk_config_get_opts();
  if (*(byte *)(iVar12 + 0xd) <= param_2) {
    r_assert_param(param_2,param_3,0x10000,0x496);
  }
  if (param_3 == 2) {
    param_2 = param_2 & 0xff;
    if (*(int *)(&lld_sync_env + param_2 * 4) == 0) {
      r_assert_err(0,0x10000,0x45d);
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
    iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
    if (iVar12 == 0) {
      r_assert_err(0,0x10000,0x445);
      return;
    }
    bVar2 = *(byte *)(iVar12 + 0x55);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400,param_1);
    iVar9 = (uint)bVar2 * 0x5a;
    uVar3 = *(ushort *)(iVar9 + 0x16 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar11 + iVar9 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(ushort *)(iVar11 + iVar9 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = *(undefined2 *)(iVar9 + 0xe + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_34 = CONCAT22(uVar6,*(undefined2 *)(iVar9 + 0xc + iVar11));
    r_emi_get_mem_addr_by_offset(0x400);
    r_emi_get_mem_addr_by_offset(0x400);
    r_emi_get_mem_addr_by_offset(0x400);
    r_co_nb_good_le_channels(&stack0xffffffd8);
    if (*(char *)(iVar12 + 100) == '\0') {
      uVar15 = *(uint *)(iVar12 + 4) * 0x271;
      iVar11 = (int)((ulonglong)*(uint *)(iVar12 + 4) * 0x271 >> 0x20);
      uVar13 = *(int *)(iVar12 + 8) + uVar15;
      bVar7 = uVar13 < uVar15;
    }
    else {
      uVar15 = *(uint *)(iVar12 + 0x44) * 0x271;
      uVar13 = (int)*(short *)(iVar12 + 0x48) + uVar15;
      bVar7 = uVar13 < uVar15;
      iVar11 = (int)((ulonglong)*(uint *)(iVar12 + 0x44) * 0x271 >> 0x20) +
               ((int)*(short *)(iVar12 + 0x48) >> 0x1f);
    }
    r_ble_log_internal_x4
              (0x404500d6,uStack_34,((uint)bVar7 + iVar11) * -0x80000000 | uVar13 >> 1,
               (uint)*(ushort *)(iVar12 + 0x4a) | (uint)(param_3 != 0) << 0x18 |
               (uint)*(byte *)(iVar12 + 0x55) << 0x10,
               ((uVar4 & 0xc) << 2 | uVar5 & 3) << 8 | uVar3 & 0x3f);
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
    acStack_41[0] = param_3 != 0;
    if (*(char *)(iVar12 + 0x5b) != '\x02') {
r_lld_sync_sched:
      iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
      uStack_34 = uStack_34 & 0xffffff;
      do {
        cVar1 = acStack_41[0];
        bVar2 = DAT_00013065;
        cVar16 = co_sca2ppm;
        if (acStack_41[0] != '\0') {
          if (0xff < (uint)*(byte *)(iVar12 + 0x16) + (uint)DAT_00013065) {
            r_assert_err(0,0x10000,0x342);
          }
          cVar16 = bVar2 + *(char *)(iVar12 + 0x16);
        }
        *(char *)(iVar12 + 0x16) = cVar16;
        if (*(char *)(iVar12 + 99) == '\x01') {
          uVar13 = *(uint *)(iVar12 + 0x2c);
          bVar2 = *(byte *)(iVar12 + 0x31);
          iVar9 = (int)*(short *)(iVar12 + 0x28);
          uVar15 = *(uint *)(iVar12 + 0x24);
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
            uVar13 = iVar9 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar12 + 0x44)) & 0xfffffff;
            if (uVar13 != 0) {
              uVar3 = *(ushort *)(iVar12 + 0x4a);
              uVar15 = *(uint *)(iVar12 + 0x40);
              if (((uint)uVar3 - (uint)*(ushort *)(iVar12 + 0x4e) & 0xffff) < 0x7fff) {
                iVar9 = ((uVar15 - 1) + uVar13) / uVar15 << 0x10;
              }
              else {
                iVar9 = ((*(ushort *)(iVar12 + 0x4e) + 1) - (uint)uVar3) * 0x10000;
                *(undefined1 *)(iVar12 + 100) = 0;
              }
              *(ushort *)(iVar12 + 0x4a) = uVar3 + (short)((uint)iVar9 >> 0x10);
              *(uint *)(iVar12 + 0x44) =
                   (iVar9 >> 0x10) * uVar15 + *(int *)(iVar12 + 0x44) & 0xfffffff;
            }
          }
          else {
            r_lld_read_clock();
          }
          if (*(byte *)(iVar12 + 0x57) == 0) {
            uVar13 = *(int *)(iVar12 + 0x40) * 6;
          }
          else {
            uVar13 = *(uint *)(iVar12 + 0x34);
          }
          if (uVar13 < (*(int *)(iVar12 + 0x44) - *(int *)(iVar12 + 0x3c) & 0xfffffffU)) {
            r_ble_log_internal_x4
                      (0x600500d4,*(undefined4 *)(iVar12 + 0x40),
                       (uint)*(ushort *)(iVar12 + 0x4a) | param_2 << 0x10 |
                       (uint)*(byte *)(iVar12 + 0x57) << 0x18);
_L224:
            r_lld_sync_cleanup(param_2,8);
            return;
          }
          iVar9 = r_rwip_active_check();
          uVar13 = 0x14;
          if (iVar9 == 0) {
            uVar13 = (uint)*(ushort *)(_p_lld_env + 0xd4);
          }
          iVar9 = (((uint)((*(int *)(iVar12 + 0x44) - *(int *)(iVar12 + 0x38)) * 0x10) >> 8) *
                  (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar12 + 0x5a) * 2) + uVar13)) / 100 +
                  0x10;
          uVar13 = iVar9 * 2;
          uVar15 = *(int *)(iVar12 + 0x44) - uVar13 / 0x271 & 0xfffffff;
          uVar14 = (uint)*(ushort *)(iVar12 + 0x48) + iVar9 * -2 + (uVar13 / 0x271) * 0x271;
          iVar9 = (int)(uVar14 * 0x10000) >> 0x10;
          if (iVar9 < 0) {
            uVar15 = uVar15 - 1 & 0xfffffff;
            iVar9 = (int)(((uVar14 & 0xffff) + 0x271) * 0x10000) >> 0x10;
          }
          if (*(char *)(iVar12 + 0x57) == '\0') {
            iVar11 = 300;
            if (*(char *)(iVar12 + 0x56) == '\0') {
              iVar11 = 0x1e;
            }
            uVar13 = uVar13 + iVar11;
            if (((uint)(*(int *)(iVar12 + 0x40) * 0x271) >> 1) - 0x96 < uVar13 >> 1) {
              r_ble_log_internal_x3(0x400500d5,(uint)*(ushort *)(iVar12 + 0x4a) | param_2 << 0x10);
              goto _L224;
            }
          }
          bVar2 = *(byte *)(iVar12 + 0x58);
          *(undefined2 *)(iVar12 + 0x52) = 0;
        }
        *(uint *)(iVar12 + 4) = uVar15;
        uVar15 = (uint)_DAT_0001306e;
        *(int *)(iVar12 + 8) = iVar9;
        uVar15 = uVar13 * 2 + uVar15 +
                 (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar2 * 2) * 2;
        if (400000 < uVar15) {
          uVar15 = 400000;
        }
        *(uint *)(iVar12 + 0x10) = uVar15;
        r_lld_sync_insert_eco(param_2,acStack_41,uVar13,(int)&uStack_34 + 3);
        if (uStack_34._3_1_ != '\0') {
          return;
        }
      } while( true );
    }
  }
  else {
    if (param_3 != 4) {
      r_assert_param(param_2,param_3,0x10000,0x4ac);
      return;
    }
    param_2 = param_2 & 0xff;
    iVar12 = *(int *)(&lld_sync_env + param_2 * 4);
    if (iVar12 == 0) {
      r_assert_err(0,0x10000,0x489);
      return;
    }
    r_ble_log_internal_x2
              (0x404500d7,
               (uint)*(ushort *)(iVar12 + 0x4a) | param_2 << 0x10 |
               (uint)*(byte *)(iVar12 + 99) << 0x18,*(undefined1 *)(iVar12 + 0x5b));
    r_sch_arb_remove(iVar12,1);
    if (*(char *)(iVar12 + 99) == '\x01') {
      r_lld_sync_trunc_ind(param_2);
      *(undefined1 *)(iVar12 + 99) = 0;
    }
    param_2 = (uint)*(byte *)(iVar12 + 0x55);
    if (*(char *)(iVar12 + 0x5b) != '\x02') {
      acStack_41[0] = true;
      goto r_lld_sync_sched;
    }
  }
  piVar8 = (int *)(&lld_sync_env + param_2 * 4);
  if (*piVar8 != 0) {
    r_ble_log_internal_x1(0x400500cb,(uint)*(ushort *)(*piVar8 + 0x4a) | param_2 << 0x10);
    puVar10 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar10 = (char)param_2;
    puVar10[1] = 0;
    r_ke_msg_send();
    r_ke_free(*piVar8);
    *piVar8 = 0;
  }
  return;
}

