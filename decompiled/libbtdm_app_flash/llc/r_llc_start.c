/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_llc_start(uint param_1,undefined4 *param_2,void *param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  void *__src;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined2 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  char cStack_24;
  byte bStack_23;
  undefined2 uStack_22;
  
  iVar3 = r_sdk_config_get_opts();
  iVar7 = 9;
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    piVar8 = (int *)(&llc_env + param_1 * 4);
    if (*piVar8 == 0) {
      puVar4 = (undefined4 *)r_ke_malloc(0x4c);
      *piVar8 = (int)puVar4;
      iVar7 = 7;
      if (puVar4 != (undefined4 *)0x0) {
        r_ke_state_set(param_1 << 8 | 1,0);
        r_co_list_init(puVar4 + 10);
        *(undefined1 *)((int)puVar4 + 0x45) = 0;
        *(undefined2 *)((int)puVar4 + 0x46) = 0;
        *(byte *)(puVar4 + 0x11) = *(byte *)(puVar4 + 0x11) & 0xf0;
        *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)((int)param_2 + 10);
        uVar6 = *(undefined2 *)(param_2 + 3);
        *(undefined2 *)((int)puVar4 + 0x42) = 0;
        *(undefined1 *)((int)puVar4 + 0x49) = 0;
        *(undefined2 *)(puVar4 + 4) = uVar6;
        *(undefined2 *)((int)puVar4 + 0x12) = *(undefined2 *)((int)param_2 + 0xe);
        memcpy(puVar4 + 2,param_2 + 4,5);
        __src = (void *)r_llm_le_features_get_hack();
        memcpy(puVar4 + 0xc,__src,8);
        iVar3 = r_sdk_config_get_opts();
        if ((param_1 < *(byte *)(iVar3 + 0xd)) && (iVar3 = *piVar8, iVar3 != 0)) {
          *(byte *)(iVar3 + 0x30) = *(byte *)(iVar3 + 0x30) & 0xfb;
        }
        *(undefined2 *)(puVar4 + 5) = 0x1b;
        bVar1 = *(byte *)(param_2 + 9);
        cVar2 = (&co_rate_to_phy)[bVar1];
        if (cVar2 == '\x03') {
          uVar6 = 0xa90;
        }
        else {
          uVar6 = 0x148;
        }
        *(undefined2 *)(puVar4 + 6) = uVar6;
        *(undefined2 *)((int)puVar4 + 0x1a) = uVar6;
        *(undefined2 *)((int)puVar4 + 0x1e) = 0x207;
        *(undefined2 *)((int)puVar4 + 0x16) = 0x1b;
        *(char *)(puVar4 + 7) = cVar2;
        *(char *)((int)puVar4 + 0x1d) = cVar2;
        memcpy(puVar4 + 8,param_3,8);
        if (cVar2 == '\x03') {
          uVar5 = *(ushort *)((int)puVar4 + 0x22);
          if (uVar5 < 0xa90) {
            uVar5 = 0xa90;
          }
          *(ushort *)((int)puVar4 + 0x22) = uVar5;
        }
        cStack_24 = *(char *)((int)param_2 + 0x25);
        *puVar4 = 0;
        *(ushort *)((int)puVar4 + 0x42) =
             (ushort)(cStack_24 == '\0') | *(ushort *)((int)puVar4 + 0x42) & 0xfffe;
        uStack_48 = *param_2;
        puVar4[1] = 0;
        uStack_44 = *(undefined2 *)(param_2 + 1);
        uStack_42 = *(undefined1 *)((int)param_2 + 6);
        uStack_41 = *(undefined1 *)((int)param_2 + 7);
        uStack_40 = param_2[2];
        uStack_3c = param_2[3];
        uStack_38 = param_2[4];
        uStack_34 = *(undefined1 *)(param_2 + 5);
        uStack_33 = *(undefined1 *)((int)param_2 + 0x15);
        uStack_32 = *(undefined1 *)((int)param_2 + 0x16);
        uStack_30 = *(undefined2 *)(param_2 + 6);
        uStack_2c = param_2[7];
        uStack_28 = param_2[8];
        uStack_22 = *(undefined2 *)((int)param_2 + 0x26);
        bStack_23 = bVar1;
        iVar7 = r_lld_con_start_eco(param_1,&uStack_48);
        if (DAT_00011078 != '\0') {
          iVar3 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar3 + 0x20) != '\0') {
            r_llc_le_ping_set(param_1,3000);
          }
        }
        if (DAT_00011079 != '\0') {
          iVar3 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar3 + 0x18) != '\0') {
            r_phy_upd_proc_start(param_1);
          }
        }
        if (DAT_00011077 != '\0') {
          r_dl_upd_proc_start(param_1);
        }
      }
    }
    else {
      r_assert_param(param_1,"llc.c",0x124);
      iVar7 = 0xff;
    }
    r_ble_log_internal_x1(0x400f0077,iVar7 << 8 | param_1);
  }
  return iVar7;
}

