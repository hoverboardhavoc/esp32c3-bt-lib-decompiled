/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_task_schedule(void)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined4 *)r_co_list_pop_front(&ke_env);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    iVar2 = r_ke_is_free(puVar1);
    if (iVar2 == 0) {
      pcVar3 = (code *)r_ke_task_handler_get_overwrite(puVar1);
      if (pcVar3 == (code *)0x0) {
        r_assert_warn(*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xb8)
        ;
      }
      else {
        r_ke_task_handler_pre(puVar1);
        iVar2 = (*pcVar3)(*(undefined2 *)(puVar1 + 1),puVar1 + 3,*(undefined2 *)((int)puVar1 + 6),
                          *(undefined2 *)(puVar1 + 2));
        if (iVar2 == 1) goto _L52;
        if (iVar2 == 2) {
          r_co_list_push_back(&ke_env,puVar1);
          iVar2 = r_sdk_config_get_opts_ext();
          if ((*(uint *)(iVar2 + 0x28) & 2) != 0) {
            iVar2 = r_sdk_config_get_opts_ext();
            if (*(byte *)(iVar2 + 0x2c) < 3) {
              r_ble_log_internal_x1(0x4045000b,puVar1);
            }
          }
          goto _L52;
        }
        if (iVar2 != 0) {
          r_assert_err(0,"ke_task.c",0xdc);
          goto _L52;
        }
      }
      r_ke_msg_free(puVar1);
    }
    else {
      r_assert_param(*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xb1);
    }
  }
_L52:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    r_ke_event_clear(3);
  }
                    /* WARNING: Could not recover jumptable at 0x00010314. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

