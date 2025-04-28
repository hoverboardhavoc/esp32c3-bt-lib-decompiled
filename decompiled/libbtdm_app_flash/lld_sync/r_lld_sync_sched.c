/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_sched(uint param_1,char param_2)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char cVar10;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_31[0] = '\0';
  acStack_41[0] = param_2;
  do {
    cVar3 = acStack_41[0];
    bVar1 = DAT_00013065;
    cVar10 = co_sca2ppm;
    if (acStack_41[0] != '\0') {
      if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,0x10000,0x337);
      }
      cVar10 = bVar1 + *(char *)(iVar4 + 0x16);
    }
    *(char *)(iVar4 + 0x16) = cVar10;
    if (*(char *)(iVar4 + 99) == '\x01') {
      uVar5 = *(uint *)(iVar4 + 0x2c);
      bVar1 = *(byte *)(iVar4 + 0x31);
      iVar7 = (int)*(short *)(iVar4 + 0x28);
      uVar6 = *(uint *)(iVar4 + 0x24);
    }
    else {
      iVar7 = 1;
      if ((((*(char *)(iVar4 + 100) != '\0') && (*(char *)(iVar4 + 0x62) == '\0')) &&
          (*(ushort *)(iVar4 + 0x4c) != 0)) && (iVar7 = -1, cVar3 == '\0')) {
        iVar8 = *(ushort *)(iVar4 + 0x4c) + 1;
        iVar7 = iVar8 * 0x10000 >> 0x10;
        *(short *)(iVar4 + 0x4e) = (short)iVar8 + *(short *)(iVar4 + 0x4a);
      }
      *(short *)(iVar4 + 0x4a) = *(short *)(iVar4 + 0x4a) + (short)iVar7;
      *(uint *)(iVar4 + 0x44) = iVar7 * *(int *)(iVar4 + 0x40) + *(int *)(iVar4 + 0x44) & 0xfffffff;
      iVar7 = r_lld_read_clock();
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) + iVar7 & 0xfffffff) < 0x8000001) {
        iVar7 = r_lld_read_clock();
        uVar5 = iVar7 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) & 0xfffffff;
        if (uVar5 != 0) {
          uVar2 = *(ushort *)(iVar4 + 0x4a);
          uVar6 = *(uint *)(iVar4 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar4 + 0x4e) & 0xffff) < 0x7fff) {
            iVar7 = ((uVar6 - 1) + uVar5) / uVar6 << 0x10;
          }
          else {
            iVar7 = ((*(ushort *)(iVar4 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar4 + 100) = 0;
          }
          *(ushort *)(iVar4 + 0x4a) = uVar2 + (short)((uint)iVar7 >> 0x10);
          *(uint *)(iVar4 + 0x44) = (iVar7 >> 0x10) * uVar6 + *(int *)(iVar4 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        uVar5 = *(int *)(iVar4 + 0x40) * 6;
      }
      else {
        uVar5 = *(uint *)(iVar4 + 0x34);
      }
      if (uVar5 < (*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x3c) & 0xfffffffU)) {
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x40020004,
                     (uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | (uint)*(byte *)(iVar4 + 0x57) << 8 |
                     param_1,uVar5,*(undefined4 *)(iVar4 + 0x44));
        }
_L225:
        r_lld_sync_cleanup(param_1,8);
        return;
      }
      iVar7 = r_rwip_active_check();
      uVar5 = 0x14;
      if (iVar7 == 0) {
        uVar5 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar7 = (((uint)((*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar4 + 0x5a) * 2) + uVar5)) / 100 + 0x10;
      uVar5 = iVar7 * 2;
      uVar6 = *(int *)(iVar4 + 0x44) - uVar5 / 0x271 & 0xfffffff;
      uVar9 = (uint)*(ushort *)(iVar4 + 0x48) + iVar7 * -2 + (uVar5 / 0x271) * 0x271;
      iVar7 = (int)(uVar9 * 0x10000) >> 0x10;
      if (iVar7 < 0) {
        uVar6 = uVar6 - 1 & 0xfffffff;
        iVar7 = (int)(((uVar9 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        iVar8 = 300;
        if (*(char *)(iVar4 + 0x56) == '\0') {
          iVar8 = 0x1e;
        }
        uVar5 = uVar5 + iVar8;
        if (((uint)(*(int *)(iVar4 + 0x40) * 0x271) >> 1) - 0x96 < uVar5 >> 1) {
          iVar7 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
             (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
            r_ble_log_internal_x2
                      (0x40020005,(uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | param_1,uVar5);
          }
          goto _L225;
        }
      }
      bVar1 = *(byte *)(iVar4 + 0x58);
      *(undefined2 *)(iVar4 + 0x52) = 0;
    }
    *(uint *)(iVar4 + 4) = uVar6;
    uVar6 = (uint)_DAT_0001306e;
    *(int *)(iVar4 + 8) = iVar7;
    uVar5 = uVar5 * 2 + uVar6 + (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) * 2;
    if (400000 < uVar5) {
      uVar5 = 400000;
    }
    *(uint *)(iVar4 + 0x10) = uVar5;
    r_lld_sync_insert_eco(param_1,acStack_41,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

