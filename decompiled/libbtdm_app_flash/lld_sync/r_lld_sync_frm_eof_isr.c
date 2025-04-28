/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_eof_isr(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char cVar11;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,0x10000,0x41b);
    return;
  }
  bVar1 = *(byte *)(iVar4 + 0x55);
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x40420008,(uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | param_2 << 8 | param_1);
  }
  r_sch_arb_remove(iVar4,1);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  iVar10 = (uint)bVar1 * 0x5a + 0x18;
  if ((*(ushort *)(iVar6 + iVar10) >> 10 & 1) != 0) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar6 + iVar10);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar10) = uVar2 & 0xfbff;
    if (*(char *)(iVar4 + 0x62) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar4 + 99) = 0;
  }
  r_lld_sync_process_pkt_rx(param_1);
  if (((*(char *)(iVar4 + 99) == '\x02') ||
      ((*(char *)(iVar4 + 100) == '\0' && (*(char *)(iVar4 + 99) == '\x01')))) &&
     (*(char *)(iVar4 + 0x62) == '\x01')) {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar4 + 99) = 0;
  }
  if (*(char *)(iVar4 + 0x5b) == '\x02') {
    if (*(int *)(&lld_sync_env + param_1 * 4) != 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x80) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40020002,
                   (uint)*(ushort *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x4a) << 0x10 | param_1
                  );
      }
      puVar5 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
      *puVar5 = (char)param_1;
      puVar5[1] = 0;
      r_ke_msg_send();
      r_ke_free(*(undefined4 *)(&lld_sync_env + param_1 * 4));
      *(undefined4 *)(&lld_sync_env + param_1 * 4) = 0;
    }
    return;
  }
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_41[0] = (char)param_2;
  acStack_31[0] = '\0';
  do {
    cVar3 = acStack_41[0];
    bVar1 = DAT_00013065;
    cVar11 = co_sca2ppm;
    if (acStack_41[0] != '\0') {
      if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,0x10000,0x337);
      }
      cVar11 = bVar1 + *(char *)(iVar4 + 0x16);
    }
    *(char *)(iVar4 + 0x16) = cVar11;
    if (*(char *)(iVar4 + 99) == '\x01') {
      uVar7 = *(uint *)(iVar4 + 0x2c);
      bVar1 = *(byte *)(iVar4 + 0x31);
      iVar6 = (int)*(short *)(iVar4 + 0x28);
      uVar8 = *(uint *)(iVar4 + 0x24);
    }
    else {
      iVar6 = 1;
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
          *(ushort *)(iVar4 + 0x4a) = uVar2 + (short)((uint)iVar6 >> 0x10);
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
                     param_1,uVar7,*(undefined4 *)(iVar4 + 0x44));
        }
_L225:
        r_lld_sync_cleanup(param_1,8);
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
      uVar8 = *(int *)(iVar4 + 0x44) - uVar7 / 0x271 & 0xfffffff;
      uVar9 = (uint)*(ushort *)(iVar4 + 0x48) + iVar6 * -2 + (uVar7 / 0x271) * 0x271;
      iVar6 = (int)(uVar9 * 0x10000) >> 0x10;
      if (iVar6 < 0) {
        uVar8 = uVar8 - 1 & 0xfffffff;
        iVar6 = (int)(((uVar9 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        iVar10 = 300;
        if (*(char *)(iVar4 + 0x56) == '\0') {
          iVar10 = 0x1e;
        }
        uVar7 = uVar7 + iVar10;
        if (((uint)(*(int *)(iVar4 + 0x40) * 0x271) >> 1) - 0x96 < uVar7 >> 1) {
          iVar6 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
             (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
            r_ble_log_internal_x2
                      (0x40020005,(uint)*(ushort *)(iVar4 + 0x4a) << 0x10 | param_1,uVar7);
          }
          goto _L225;
        }
      }
      bVar1 = *(byte *)(iVar4 + 0x58);
      *(undefined2 *)(iVar4 + 0x52) = 0;
    }
    *(uint *)(iVar4 + 4) = uVar8;
    uVar8 = (uint)_DAT_0001306e;
    *(int *)(iVar4 + 8) = iVar6;
    uVar7 = uVar7 * 2 + uVar8 + (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) * 2;
    if (400000 < uVar7) {
      uVar7 = 400000;
    }
    *(uint *)(iVar4 + 0x10) = uVar7;
    r_lld_sync_insert_eco(param_1,acStack_41,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

