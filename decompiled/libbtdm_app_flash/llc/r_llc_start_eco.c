/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_start_eco(uint param_1,undefined4 *param_2,void *param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  void *__src;
  int iVar4;
  ushort *puVar5;
  ushort uVar6;
  undefined2 uVar7;
  int *piVar8;
  undefined4 uVar9;
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
  
  iVar4 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar4 + 0xd)) {
    puVar5 = (ushort *)r_llc_enc_state_get();
    uVar6 = ~(ushort)(1 << (param_1 & 0x1f));
    *puVar5 = *puVar5 & uVar6;
    puVar5[1] = uVar6 & puVar5[1];
  }
  iVar4 = r_sdk_config_get_opts();
  uVar9 = 9;
  if (param_1 < *(byte *)(iVar4 + 0xd)) {
    piVar8 = (int *)(&llc_env + param_1 * 4);
    if (*piVar8 == 0) {
      puVar3 = (undefined4 *)r_ke_malloc(0x4c);
      *piVar8 = (int)puVar3;
      uVar9 = 7;
      if (puVar3 != (undefined4 *)0x0) {
        r_ke_state_set(param_1 << 8 | 1,0);
        r_co_list_init(puVar3 + 10);
        *(undefined1 *)((int)puVar3 + 0x45) = 0;
        *(undefined2 *)((int)puVar3 + 0x46) = 0;
        *(byte *)(puVar3 + 0x11) = *(byte *)(puVar3 + 0x11) & 0xf0;
        *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)((int)param_2 + 10);
        uVar7 = *(undefined2 *)(param_2 + 3);
        *(undefined2 *)((int)puVar3 + 0x42) = 0;
        *(undefined1 *)((int)puVar3 + 0x49) = 0;
        *(undefined2 *)(puVar3 + 4) = uVar7;
        *(undefined2 *)((int)puVar3 + 0x12) = *(undefined2 *)((int)param_2 + 0xe);
        memcpy(puVar3 + 2,param_2 + 4,5);
        __src = (void *)r_llm_le_features_get();
        memcpy(puVar3 + 0xc,__src,8);
        iVar4 = r_sdk_config_get_opts();
        if ((param_1 < *(byte *)(iVar4 + 0xd)) && (iVar4 = *piVar8, iVar4 != 0)) {
          *(byte *)(iVar4 + 0x30) = *(byte *)(iVar4 + 0x30) & 0xfb;
        }
        *(undefined2 *)(puVar3 + 5) = 0x1b;
        bVar1 = *(byte *)(param_2 + 9);
        cVar2 = (&co_rate_to_phy)[bVar1];
        uVar7 = 0x148;
        if (cVar2 == '\x03') {
          uVar7 = 0xa90;
        }
        *(undefined2 *)(puVar3 + 6) = uVar7;
        *(undefined2 *)((int)puVar3 + 0x1a) = uVar7;
        *(undefined2 *)((int)puVar3 + 0x1e) = 0x207;
        *(undefined2 *)((int)puVar3 + 0x16) = 0x1b;
        *(char *)(puVar3 + 7) = cVar2;
        *(char *)((int)puVar3 + 0x1d) = cVar2;
        memcpy(puVar3 + 8,param_3,8);
        if (cVar2 == '\x03') {
          uVar6 = *(ushort *)((int)puVar3 + 0x22);
          if (uVar6 < 0xa90) {
            uVar6 = 0xa90;
          }
          *(ushort *)((int)puVar3 + 0x22) = uVar6;
        }
        cStack_24 = *(char *)((int)param_2 + 0x25);
        *puVar3 = 0;
        *(ushort *)((int)puVar3 + 0x42) =
             (ushort)(cStack_24 == '\0') | *(ushort *)((int)puVar3 + 0x42) & 0xfffe;
        uStack_48 = *param_2;
        puVar3[1] = 0;
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
        uVar9 = r_lld_con_start_eco(param_1,&uStack_48);
        if ((DAT_00011074 != '\0') &&
           (iVar4 = r_sdk_config_get_opts_ext(), *(char *)(iVar4 + 0x20) != '\0')) {
          r_llc_le_ping_set(param_1,3000);
        }
        if ((DAT_00011075 != '\0') &&
           (iVar4 = r_sdk_config_get_opts_ext(), *(char *)(iVar4 + 0x18) != '\0')) {
          r_phy_upd_proc_start(param_1);
        }
        if (DAT_00011073 != '\0') {
          r_dl_upd_proc_start(param_1);
        }
      }
    }
    else {
      r_assert_param(param_1,"llc.c",0x121);
      uVar9 = 0xff;
    }
  }
  return uVar9;
}

