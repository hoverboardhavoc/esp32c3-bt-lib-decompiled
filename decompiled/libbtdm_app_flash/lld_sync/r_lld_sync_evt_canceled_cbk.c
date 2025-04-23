/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  char acStack_41 [16];
  char acStack_31 [13];
  
  if (param_1 == 0) {
    r_assert_err(0x10000,0x4ee);
    return;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x4042000a,
               (uint)*(byte *)(param_1 + 0x55) |
               (uint)*(byte *)(param_1 + 99) << 0x10 | (uint)*(byte *)(param_1 + 0x5b) << 8,
               *(undefined2 *)(param_1 + 0x4a));
  }
  if (*(char *)(param_1 + 0x5b) != '\0') {
    r_assert_param(0,0x10000,0x4d9);
  }
  if (*(char *)(param_1 + 99) == '\x01') {
    r_lld_sync_trunc_ind(*(undefined1 *)(param_1 + 0x55));
    *(undefined1 *)(param_1 + 99) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0x55);
  uVar6 = (uint)bVar1;
  if (*(char *)(param_1 + 0x5b) == '\x02') {
    if (*(int *)(&lld_sync_env + uVar6 * 4) != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
         (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40020002,
                   (uint)*(ushort *)(*(int *)(&lld_sync_env + uVar6 * 4) + 0x4a) << 0x10 | uVar6);
      }
      pbVar4 = (byte *)r_ke_msg_alloc(0x205,0,0xff,2);
      *pbVar4 = bVar1;
      pbVar4[1] = 0;
      r_ke_msg_send();
      r_ke_free(*(undefined4 *)(&lld_sync_env + uVar6 * 4));
      *(undefined4 *)(&lld_sync_env + uVar6 * 4) = 0;
    }
    return;
  }
  iVar5 = *(int *)(&lld_sync_env + uVar6 * 4);
  acStack_41[0] = '\x01';
  acStack_31[0] = '\0';
  do {
    cVar3 = acStack_41[0];
    bVar1 = DAT_00013065;
    if (acStack_31[0] != '\0') {
      return;
    }
    cVar12 = lld_sync_max_aux_dur_tab;
    if (acStack_41[0] != '\0') {
      if (0xff < (uint)*(byte *)(iVar5 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,0x10000,0x337);
      }
      cVar12 = bVar1 + *(char *)(iVar5 + 0x16);
    }
    *(char *)(iVar5 + 0x16) = cVar12;
    iVar10 = 1;
    if (*(char *)(iVar5 + 99) == '\x01') {
      uVar7 = *(uint *)(iVar5 + 0x2c);
      bVar1 = *(byte *)(iVar5 + 0x31);
      iVar10 = (int)*(short *)(iVar5 + 0x28);
      uVar8 = *(uint *)(iVar5 + 0x24);
    }
    else {
      if ((((*(char *)(iVar5 + 100) != '\0') && (*(char *)(iVar5 + 0x62) == '\0')) &&
          (*(ushort *)(iVar5 + 0x4c) != 0)) && (iVar10 = -1, cVar3 == '\0')) {
        iVar9 = *(ushort *)(iVar5 + 0x4c) + 1;
        iVar10 = iVar9 * 0x10000 >> 0x10;
        *(short *)(iVar5 + 0x4e) = (short)iVar9 + *(short *)(iVar5 + 0x4a);
      }
      *(short *)(iVar5 + 0x4a) = *(short *)(iVar5 + 0x4a) + (short)iVar10;
      *(uint *)(iVar5 + 0x44) = iVar10 * *(int *)(iVar5 + 0x40) + *(int *)(iVar5 + 0x44) & 0xfffffff
      ;
      iVar10 = r_lld_read_clock();
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar5 + 0x44)) + iVar10 & 0xfffffff) < 0x8000001) {
        iVar10 = r_lld_read_clock();
        uVar7 = iVar10 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar5 + 0x44)) & 0xfffffff;
        if (uVar7 != 0) {
          uVar2 = *(ushort *)(iVar5 + 0x4a);
          uVar8 = *(uint *)(iVar5 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar5 + 0x4e) & 0xffff) < 0x7fff) {
            iVar10 = ((uVar8 - 1) + uVar7) / uVar8 << 0x10;
          }
          else {
            iVar10 = ((*(ushort *)(iVar5 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar5 + 100) = 0;
          }
          *(ushort *)(iVar5 + 0x4a) = uVar2 + (short)((uint)iVar10 >> 0x10);
          *(uint *)(iVar5 + 0x44) = (iVar10 >> 0x10) * uVar8 + *(int *)(iVar5 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar5 + 0x57) == '\0') {
        uVar7 = *(int *)(iVar5 + 0x40) * 6;
      }
      else {
        uVar7 = *(uint *)(iVar5 + 0x34);
      }
      if (uVar7 < (*(int *)(iVar5 + 0x44) - *(int *)(iVar5 + 0x3c) & 0xfffffffU)) {
        iVar10 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar10 + 0x28) & 0x80) != 0) &&
           (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x40020004,
                     (uint)*(ushort *)(iVar5 + 0x4a) << 0x10 | (uint)*(byte *)(iVar5 + 0x57) << 8 |
                     uVar6,uVar7,*(undefined4 *)(iVar5 + 0x44));
        }
_L210:
        r_lld_sync_cleanup(uVar6,8);
        return;
      }
      iVar10 = r_rwip_active_check();
      uVar7 = 0x14;
      if (iVar10 == 0) {
        uVar7 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar10 = (((uint)(*(int *)(iVar5 + 0x44) - *(int *)(iVar5 + 0x38)) >> 4 & 0xffffff) *
               (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar5 + 0x5a) * 2) + uVar7)) / 100 + 0x10;
      uVar7 = iVar10 * 2;
      uVar8 = *(int *)(iVar5 + 0x44) - uVar7 / 0x271 & 0xfffffff;
      uVar11 = (uint)*(ushort *)(iVar5 + 0x48) + iVar10 * -2 + (uVar7 / 0x271) * 0x271;
      iVar10 = (int)(uVar11 * 0x10000) >> 0x10;
      if (iVar10 < 0) {
        uVar8 = uVar8 - 1 & 0xfffffff;
        iVar10 = (int)(((uVar11 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if ((*(char *)(iVar5 + 0x57) == '\0') &&
         (uVar7 = uVar7 + (-(uint)(*(char *)(iVar5 + 0x56) == '\0') & 0xfffffef2) + 300,
         ((uint)(*(int *)(iVar5 + 0x40) * 0x271) >> 1) - 0x96 < uVar7 >> 1)) {
        iVar10 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar10 + 0x28) & 0x80) != 0) &&
           (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 3)) {
          r_ble_log_internal_x2(0x40020005,(uint)*(ushort *)(iVar5 + 0x4a) << 0x10 | uVar6,uVar7);
        }
        goto _L210;
      }
      bVar1 = *(byte *)(iVar5 + 0x58);
      *(undefined2 *)(iVar5 + 0x52) = 0;
    }
    *(int *)(iVar5 + 8) = iVar10;
    *(uint *)(iVar5 + 4) = uVar8;
    uVar7 = (*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) + uVar7) * 2 +
            (uint)_sdk_cfg_priv_opts;
    if (400000 < uVar7) {
      uVar7 = 400000;
    }
    *(uint *)(iVar5 + 0x10) = uVar7;
    r_lld_sync_insert_eco(uVar6,acStack_41,acStack_31);
  } while( true );
}

