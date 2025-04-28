/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char cVar11;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar6 = r_sdk_config_get_opts();
  if (*(byte *)(iVar6 + 0xd) <= param_2) {
    r_assert_param(param_2,param_3,0x10000,0x46c);
  }
  if (param_3 == 2) {
    param_2 = param_2 & 0xff;
    if (*(int *)(&lld_sync_env + param_2 * 4) == 0) {
      r_assert_err(0,0x10000,0x433);
      return;
    }
    iVar6 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
       (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 2)) {
      r_ble_log_internal_x1(0x20a2000c,param_2);
    }
    iVar6 = *(int *)(&lld_sync_env + param_2 * 4);
    while (iVar5 = r_lld_rxdesc_check_hack(param_2), iVar5 != 0) {
      cVar1 = *(char *)(iVar6 + 99);
      if (*(ushort *)(iVar6 + 0x52) < 0x673) {
        r_lld_sync_process_pkt_rx_aux_sync_ind(param_2);
        r_lld_sync_process_pkt_rx_pkt_check(param_2,cVar1 == '\0');
      }
      r_lld_rxdesc_free();
    }
    return;
  }
  if (param_3 < 3) {
    param_2 = param_2 & 0xff;
    iVar6 = *(int *)(&lld_sync_env + param_2 * 4);
    if (iVar6 == 0) {
      r_assert_err(0,0x10000,0x41b);
      return;
    }
    bVar2 = *(byte *)(iVar6 + 0x55);
    iVar5 = r_sdk_config_get_opts_ext(param_1);
    if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40420008,
                 (uint)*(ushort *)(iVar6 + 0x4a) << 0x10 | (uint)(param_3 != 0) << 8 | param_2);
    }
    r_sch_arb_remove(iVar6,1);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    iVar10 = (uint)bVar2 * 0x5a + 0x18;
    if ((*(ushort *)(iVar5 + iVar10) >> 10 & 1) != 0) {
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar5 + iVar10);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar10) = uVar3 & 0xfbff;
      if (*(char *)(iVar6 + 0x62) == '\x01') {
        r_lld_sync_trunc_ind(param_2);
      }
      *(undefined1 *)(iVar6 + 99) = 0;
    }
    r_lld_sync_process_pkt_rx(param_2);
    if (((*(char *)(iVar6 + 99) == '\x02') ||
        ((*(char *)(iVar6 + 100) == '\0' && (*(char *)(iVar6 + 99) == '\x01')))) &&
       (*(char *)(iVar6 + 0x62) == '\x01')) {
      r_lld_sync_trunc_ind(param_2);
      *(undefined1 *)(iVar6 + 99) = 0;
    }
    acStack_41[0] = param_3 != 0;
    if (*(char *)(iVar6 + 0x5b) != '\x02') {
r_lld_sync_sched:
      iVar6 = *(int *)(&lld_sync_env + param_2 * 4);
      acStack_31[0] = '\0';
      do {
        cVar1 = acStack_41[0];
        bVar2 = DAT_00013065;
        cVar11 = co_sca2ppm;
        if (acStack_41[0] != '\0') {
          if (0xff < (uint)*(byte *)(iVar6 + 0x16) + (uint)DAT_00013065) {
            r_assert_err(0,0x10000,0x337);
          }
          cVar11 = bVar2 + *(char *)(iVar6 + 0x16);
        }
        *(char *)(iVar6 + 0x16) = cVar11;
        if (*(char *)(iVar6 + 99) == '\x01') {
          uVar7 = *(uint *)(iVar6 + 0x2c);
          bVar2 = *(byte *)(iVar6 + 0x31);
          iVar5 = (int)*(short *)(iVar6 + 0x28);
          uVar8 = *(uint *)(iVar6 + 0x24);
        }
        else {
          iVar5 = 1;
          if ((((*(char *)(iVar6 + 100) != '\0') && (*(char *)(iVar6 + 0x62) == '\0')) &&
              (*(ushort *)(iVar6 + 0x4c) != 0)) && (iVar5 = -1, cVar1 == '\0')) {
            iVar10 = *(ushort *)(iVar6 + 0x4c) + 1;
            iVar5 = iVar10 * 0x10000 >> 0x10;
            *(short *)(iVar6 + 0x4e) = (short)iVar10 + *(short *)(iVar6 + 0x4a);
          }
          *(short *)(iVar6 + 0x4a) = *(short *)(iVar6 + 0x4a) + (short)iVar5;
          *(uint *)(iVar6 + 0x44) =
               iVar5 * *(int *)(iVar6 + 0x40) + *(int *)(iVar6 + 0x44) & 0xfffffff;
          iVar5 = r_lld_read_clock();
          if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar6 + 0x44)) + iVar5 & 0xfffffff) < 0x8000001
             ) {
            iVar5 = r_lld_read_clock();
            uVar7 = iVar5 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar6 + 0x44)) & 0xfffffff;
            if (uVar7 != 0) {
              uVar3 = *(ushort *)(iVar6 + 0x4a);
              uVar8 = *(uint *)(iVar6 + 0x40);
              if (((uint)uVar3 - (uint)*(ushort *)(iVar6 + 0x4e) & 0xffff) < 0x7fff) {
                iVar5 = ((uVar8 - 1) + uVar7) / uVar8 << 0x10;
              }
              else {
                iVar5 = ((*(ushort *)(iVar6 + 0x4e) + 1) - (uint)uVar3) * 0x10000;
                *(undefined1 *)(iVar6 + 100) = 0;
              }
              *(ushort *)(iVar6 + 0x4a) = uVar3 + (short)((uint)iVar5 >> 0x10);
              *(uint *)(iVar6 + 0x44) = (iVar5 >> 0x10) * uVar8 + *(int *)(iVar6 + 0x44) & 0xfffffff
              ;
            }
          }
          else {
            r_lld_read_clock();
          }
          if (*(char *)(iVar6 + 0x57) == '\0') {
            uVar7 = *(int *)(iVar6 + 0x40) * 6;
          }
          else {
            uVar7 = *(uint *)(iVar6 + 0x34);
          }
          if (uVar7 < (*(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x3c) & 0xfffffffU)) {
            iVar5 = r_sdk_config_get_opts_ext();
            if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
               (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
              r_ble_log_internal_x3
                        (0x40020004,
                         (uint)*(ushort *)(iVar6 + 0x4a) << 0x10 |
                         (uint)*(byte *)(iVar6 + 0x57) << 8 | param_2,uVar7,
                         *(undefined4 *)(iVar6 + 0x44));
            }
_L225:
            r_lld_sync_cleanup(param_2,8);
            return;
          }
          iVar5 = r_rwip_active_check();
          uVar7 = 0x14;
          if (iVar5 == 0) {
            uVar7 = (uint)*(ushort *)(_p_lld_env + 0xd4);
          }
          iVar5 = (((uint)((*(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x38)) * 0x10) >> 8) *
                  (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar6 + 0x5a) * 2) + uVar7)) / 100 +
                  0x10;
          uVar7 = iVar5 * 2;
          uVar8 = *(int *)(iVar6 + 0x44) - uVar7 / 0x271 & 0xfffffff;
          uVar9 = (uint)*(ushort *)(iVar6 + 0x48) + iVar5 * -2 + (uVar7 / 0x271) * 0x271;
          iVar5 = (int)(uVar9 * 0x10000) >> 0x10;
          if (iVar5 < 0) {
            uVar8 = uVar8 - 1 & 0xfffffff;
            iVar5 = (int)(((uVar9 & 0xffff) + 0x271) * 0x10000) >> 0x10;
          }
          if (*(char *)(iVar6 + 0x57) == '\0') {
            iVar10 = 300;
            if (*(char *)(iVar6 + 0x56) == '\0') {
              iVar10 = 0x1e;
            }
            uVar7 = uVar7 + iVar10;
            if (((uint)(*(int *)(iVar6 + 0x40) * 0x271) >> 1) - 0x96 < uVar7 >> 1) {
              iVar5 = r_sdk_config_get_opts_ext();
              if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
                 (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
                r_ble_log_internal_x2
                          (0x40020005,(uint)*(ushort *)(iVar6 + 0x4a) << 0x10 | param_2,uVar7);
              }
              goto _L225;
            }
          }
          bVar2 = *(byte *)(iVar6 + 0x58);
          *(undefined2 *)(iVar6 + 0x52) = 0;
        }
        *(uint *)(iVar6 + 4) = uVar8;
        uVar8 = (uint)_DAT_0001306e;
        *(int *)(iVar6 + 8) = iVar5;
        uVar7 = uVar7 * 2 + uVar8 +
                (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar2 * 2) * 2;
        if (400000 < uVar7) {
          uVar7 = 400000;
        }
        *(uint *)(iVar6 + 0x10) = uVar7;
        r_lld_sync_insert_eco(param_2,acStack_41,acStack_31);
        if (acStack_31[0] != '\0') {
          return;
        }
      } while( true );
    }
  }
  else {
    if (param_3 != 4) {
      r_assert_param(param_2,param_3,0x10000,0x482);
      return;
    }
    param_2 = param_2 & 0xff;
    iVar6 = *(int *)(&lld_sync_env + param_2 * 4);
    if (iVar6 == 0) {
      r_assert_err(0,0x10000,0x45f);
      return;
    }
    iVar5 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
      r_ble_log_internal_x2
                (0x40420009,
                 (uint)*(byte *)(iVar6 + 0x5b) << 0x10 | (uint)*(byte *)(iVar6 + 99) << 8 | param_2,
                 *(undefined2 *)(iVar6 + 0x4a));
    }
    r_sch_arb_remove(iVar6,1);
    if (*(char *)(iVar6 + 99) == '\x01') {
      r_lld_sync_trunc_ind(param_2);
      *(undefined1 *)(iVar6 + 99) = 0;
    }
    param_2 = (uint)*(byte *)(iVar6 + 0x55);
    if (*(char *)(iVar6 + 0x5b) != '\x02') {
      acStack_41[0] = true;
      goto r_lld_sync_sched;
    }
  }
  if (*(int *)(&lld_sync_env + param_2 * 4) != 0) {
    iVar6 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
       (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40020002,
                 (uint)*(ushort *)(*(int *)(&lld_sync_env + param_2 * 4) + 0x4a) << 0x10 | param_2);
    }
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar4 = (char)param_2;
    puVar4[1] = 0;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_sync_env + param_2 * 4));
    *(undefined4 *)(&lld_sync_env + param_2 * 4) = 0;
  }
  return;
}

