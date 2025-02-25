/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  uint uVar11;
  char acStack_41 [16];
  char acStack_31 [9];
  
  if (param_1 == 0) {
    r_assert_err("lld_sync.c",0x4ee);
    return;
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 0x80) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x4042000a,
               (uint)*(byte *)(param_1 + 0x55) |
               (uint)*(byte *)(param_1 + 99) << 0x10 | (uint)*(byte *)(param_1 + 0x5b) << 8,
               *(undefined2 *)(param_1 + 0x4a));
  }
  if (*(char *)(param_1 + 0x5b) != '\0') {
    r_assert_param(0,"lld_sync.c",0x4d9);
  }
  if (*(char *)(param_1 + 99) == '\x01') {
    r_lld_sync_trunc_ind(*(undefined1 *)(param_1 + 0x55));
    *(undefined1 *)(param_1 + 99) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0x55);
  uVar5 = (uint)bVar1;
  if (*(char *)(param_1 + 0x5b) == '\x02') {
    if (*(int *)(&lld_sync_env + uVar5 * 4) != 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x80) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40020002,
                   (uint)*(ushort *)(*(int *)(&lld_sync_env + uVar5 * 4) + 0x4a) << 0x10 | uVar5);
      }
      pbVar3 = (byte *)r_ke_msg_alloc(0x205,0,0xff,2);
      *pbVar3 = bVar1;
      pbVar3[1] = 0;
      r_ke_msg_send();
      r_ke_free(*(undefined4 *)(&lld_sync_env + uVar5 * 4));
      *(undefined4 *)(&lld_sync_env + uVar5 * 4) = 0;
    }
    return;
  }
  iVar4 = *(int *)(&lld_sync_env + uVar5 * 4);
  acStack_41[0] = '\x01';
  acStack_31[0] = '\0';
  do {
    bVar1 = DAT_00013065;
    if (acStack_41[0] == '\0') {
      *(undefined1 *)(iVar4 + 0x16) = co_sca2ppm;
    }
    else {
      if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,"lld_sync.c",0x337);
      }
      *(byte *)(iVar4 + 0x16) = bVar1 + *(char *)(iVar4 + 0x16);
    }
    if (*(char *)(iVar4 + 99) == '\x01') {
      uVar7 = *(uint *)(iVar4 + 0x2c);
      bVar1 = *(byte *)(iVar4 + 0x31);
      iVar6 = (int)*(short *)(iVar4 + 0x28);
      uVar11 = *(uint *)(iVar4 + 0x24);
    }
    else {
      iVar6 = 1;
      if ((((*(char *)(iVar4 + 100) != '\0') && (*(char *)(iVar4 + 0x62) == '\0')) &&
          (*(short *)(iVar4 + 0x4c) != 0)) && (iVar6 = -1, acStack_41[0] == '\0')) {
        sVar10 = *(short *)(iVar4 + 0x4c) + 1;
        iVar6 = (int)sVar10;
        *(short *)(iVar4 + 0x4e) = sVar10 + *(short *)(iVar4 + 0x4a);
      }
      *(short *)(iVar4 + 0x4a) = *(short *)(iVar4 + 0x4a) + (short)iVar6;
      *(uint *)(iVar4 + 0x44) = iVar6 * *(int *)(iVar4 + 0x40) + *(int *)(iVar4 + 0x44) & 0xfffffff;
      iVar6 = r_lld_read_clock();
      if ((iVar6 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) & 0xfffffff) < 0x8000001) {
        iVar6 = r_lld_read_clock();
        uVar7 = iVar6 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) & 0xfffffff;
        if (uVar7 != 0) {
          uVar2 = *(ushort *)(iVar4 + 0x4a);
          uVar8 = *(uint *)(iVar4 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar4 + 0x4e) & 0xffff) < 0x7fff) {
            iVar6 = ((uVar8 - 1) + uVar7) / uVar8 << 0x10;
          }
          else {
            iVar6 = ((*(ushort *)(iVar4 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar4 + 100) = 0;
          }
          *(ushort *)(iVar4 + 0x4a) = (short)((uint)iVar6 >> 0x10) + uVar2;
          *(uint *)(iVar4 + 0x44) = (iVar6 >> 0x10) * uVar8 + *(int *)(iVar4 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        uVar7 = *(int *)(iVar4 + 0x40) * 6;
      }
      else {
        uVar7 = *(uint *)(iVar4 + 0x34);
      }
      if (uVar7 < (*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x3c) & 0xfffffffU)) {
        iVar6 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
           (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x40020004,
                     (uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | (uint)*(byte *)(iVar4 + 0x57) << 8 |
                     uVar5,uVar7,*(undefined4 *)(iVar4 + 0x44));
        }
_L229:
        r_lld_sync_cleanup(uVar5,8);
        return;
      }
      iVar6 = r_rwip_active_check();
      uVar7 = 0x14;
      if (iVar6 == 0) {
        uVar7 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar6 = (((uint)((*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar4 + 0x5a) * 2) + uVar7)) / 100 + 0x10;
      uVar7 = iVar6 * 2;
      uVar11 = *(int *)(iVar4 + 0x44) - uVar7 / 0x271 & 0xfffffff;
      uVar8 = (uint)*(ushort *)(iVar4 + 0x48) + iVar6 * -2 + (uVar7 / 0x271) * 0x271;
      iVar6 = (int)(short)uVar8;
      if (iVar6 < 0) {
        uVar11 = uVar11 - 1 & 0xfffffff;
        iVar6 = (int)(((uVar8 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        iVar9 = 300;
        if (*(char *)(iVar4 + 0x56) == '\0') {
          iVar9 = 0x1e;
        }
        uVar7 = uVar7 + iVar9;
        if (((uint)(*(int *)(iVar4 + 0x40) * 0x271) >> 1) - 0x96 < uVar7 >> 1) {
          iVar6 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
             (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
            r_ble_log_internal_x2(0x40020005,(uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | uVar5,uVar7);
          }
          goto _L229;
        }
      }
      *(undefined2 *)(iVar4 + 0x52) = 0;
      bVar1 = *(byte *)(iVar4 + 0x58);
    }
    uVar8 = (uint)_DAT_0001306e;
    *(uint *)(iVar4 + 4) = uVar11;
    uVar2 = *(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2);
    *(int *)(iVar4 + 8) = iVar6;
    uVar7 = uVar7 * 2 + uVar8 + (uint)uVar2 * 2;
    if (uVar7 < 0x61a81) {
      *(uint *)(iVar4 + 0x10) = uVar7;
    }
    else {
      *(undefined4 *)(iVar4 + 0x10) = 400000;
    }
    r_lld_sync_insert_eco(uVar5,acStack_41,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

