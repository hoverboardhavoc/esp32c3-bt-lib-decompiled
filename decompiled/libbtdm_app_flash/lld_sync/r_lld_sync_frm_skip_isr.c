/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_skip_isr(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  char acStack_41 [16];
  char acStack_31 [13];
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,0x10000,0x45f);
    return;
  }
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x40420009,
               (uint)*(byte *)(iVar4 + 0x5b) << 0x10 | (uint)*(byte *)(iVar4 + 99) << 8 | param_1,
               *(undefined2 *)(iVar4 + 0x4a));
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 99) == '\x01') {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar4 + 99) = 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x55);
  uVar7 = (uint)bVar1;
  if (*(char *)(iVar4 + 0x5b) == '\x02') {
    if (*(int *)(&lld_sync_env + uVar7 * 4) != 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x80) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40020002,
                   (uint)*(ushort *)(*(int *)(&lld_sync_env + uVar7 * 4) + 0x4a) << 0x10 | uVar7);
      }
      pbVar5 = (byte *)r_ke_msg_alloc(0x205,0,0xff,2);
      *pbVar5 = bVar1;
      pbVar5[1] = 0;
      r_ke_msg_send();
      r_ke_free(*(undefined4 *)(&lld_sync_env + uVar7 * 4));
      *(undefined4 *)(&lld_sync_env + uVar7 * 4) = 0;
    }
    return;
  }
  iVar4 = *(int *)(&lld_sync_env + uVar7 * 4);
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
      if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,0x10000,0x337);
      }
      cVar12 = bVar1 + *(char *)(iVar4 + 0x16);
    }
    *(char *)(iVar4 + 0x16) = cVar12;
    iVar6 = 1;
    if (*(char *)(iVar4 + 99) == '\x01') {
      uVar8 = *(uint *)(iVar4 + 0x2c);
      bVar1 = *(byte *)(iVar4 + 0x31);
      iVar6 = (int)*(short *)(iVar4 + 0x28);
      uVar9 = *(uint *)(iVar4 + 0x24);
    }
    else {
      if ((((*(char *)(iVar4 + 100) != '\0') && (*(char *)(iVar4 + 0x62) == '\0')) &&
          (*(ushort *)(iVar4 + 0x4c) != 0)) && (iVar6 = -1, cVar3 == '\0')) {
        iVar10 = *(ushort *)(iVar4 + 0x4c) + 1;
        iVar6 = iVar10 * 0x10000 >> 0x10;
        *(short *)(iVar4 + 0x4e) = (short)iVar10 + *(short *)(iVar4 + 0x4a);
      }
      *(short *)(iVar4 + 0x4a) = *(short *)(iVar4 + 0x4a) + (short)iVar6;
      *(uint *)(iVar4 + 0x44) = iVar6 * *(int *)(iVar4 + 0x40) + *(int *)(iVar4 + 0x44) & 0xfffffff;
      iVar6 = r_lld_read_clock();
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) + iVar6 & 0xfffffff) < 0x8000001) {
        iVar6 = r_lld_read_clock();
        uVar8 = iVar6 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) & 0xfffffff;
        if (uVar8 != 0) {
          uVar2 = *(ushort *)(iVar4 + 0x4a);
          uVar9 = *(uint *)(iVar4 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar4 + 0x4e) & 0xffff) < 0x7fff) {
            iVar6 = ((uVar9 - 1) + uVar8) / uVar9 << 0x10;
          }
          else {
            iVar6 = ((*(ushort *)(iVar4 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar4 + 100) = 0;
          }
          *(ushort *)(iVar4 + 0x4a) = uVar2 + (short)((uint)iVar6 >> 0x10);
          *(uint *)(iVar4 + 0x44) = (iVar6 >> 0x10) * uVar9 + *(int *)(iVar4 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        uVar8 = *(int *)(iVar4 + 0x40) * 6;
      }
      else {
        uVar8 = *(uint *)(iVar4 + 0x34);
      }
      if (uVar8 < (*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x3c) & 0xfffffffU)) {
        iVar6 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
           (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x40020004,
                     (uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | (uint)*(byte *)(iVar4 + 0x57) << 8 |
                     uVar7,uVar8,*(undefined4 *)(iVar4 + 0x44));
        }
_L210:
        r_lld_sync_cleanup(uVar7,8);
        return;
      }
      iVar6 = r_rwip_active_check();
      uVar8 = 0x14;
      if (iVar6 == 0) {
        uVar8 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar6 = (((uint)(*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x38)) >> 4 & 0xffffff) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar4 + 0x5a) * 2) + uVar8)) / 100 + 0x10;
      uVar8 = iVar6 * 2;
      uVar9 = *(int *)(iVar4 + 0x44) - uVar8 / 0x271 & 0xfffffff;
      uVar11 = (uint)*(ushort *)(iVar4 + 0x48) + iVar6 * -2 + (uVar8 / 0x271) * 0x271;
      iVar6 = (int)(uVar11 * 0x10000) >> 0x10;
      if (iVar6 < 0) {
        uVar9 = uVar9 - 1 & 0xfffffff;
        iVar6 = (int)(((uVar11 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if ((*(char *)(iVar4 + 0x57) == '\0') &&
         (uVar8 = uVar8 + (-(uint)(*(char *)(iVar4 + 0x56) == '\0') & 0xfffffef2) + 300,
         ((uint)(*(int *)(iVar4 + 0x40) * 0x271) >> 1) - 0x96 < uVar8 >> 1)) {
        iVar6 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
           (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
          r_ble_log_internal_x2(0x40020005,(uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | uVar7,uVar8);
        }
        goto _L210;
      }
      bVar1 = *(byte *)(iVar4 + 0x58);
      *(undefined2 *)(iVar4 + 0x52) = 0;
    }
    *(int *)(iVar4 + 8) = iVar6;
    *(uint *)(iVar4 + 4) = uVar9;
    uVar8 = (*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) + uVar8) * 2 +
            (uint)_sdk_cfg_priv_opts;
    if (400000 < uVar8) {
      uVar8 = 400000;
    }
    *(uint *)(iVar4 + 0x10) = uVar8;
    r_lld_sync_insert_eco(uVar7,acStack_41,acStack_31);
  } while( true );
}

